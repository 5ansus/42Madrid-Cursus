# DEV_DOC

## 1. Environment setup from scratch

### Prerequisites
- Linux host or VM
- Docker Engine
- Docker Compose v2
- GNU Make
- Internet access (first bootstrap downloads WordPress assets)

### Repository layout (developer-relevant)
- `Makefile`: wraps Docker Compose operations.
- `srcs/docker-compose.yml`: services, ports, network, volumes, secrets.
- `srcs/.env`: non-secret runtime variables (domain, users, emails).
- `secrets/*.txt`: real secrets (local only).
- `secrets/*.txt.example`: templates for required secrets.

### Prepare secrets
Create these files in `secrets/` (single-line values):
- `db_password.txt`
- `db_root_password.txt`
- `wp_admin_password.txt`
- `wp_user_password.txt`

### Host-path constraint
Current volume paths are hardcoded to `/home/sanferna/data/...`.
If your user is different, update:
- host folder creation in `Makefile`
- `device:` paths in `srcs/docker-compose.yml`

## 2. Build and launch with Makefile and Docker Compose
From repository root:

Build images:
```bash
make build
```

Build + launch in detached mode:
```bash
make up
```

Stop:
```bash
make down
```

Restart:
```bash
make restart
```

Show status:
```bash
make ps
```

Follow logs:
```bash
make logs
```

### Equivalent Docker Compose command
The Makefile uses:
```bash
docker compose -f srcs/docker-compose.yml --env-file srcs/.env <command>
```

## 3. Manage containers and volumes
Stop and remove containers + volumes:
```bash
make clean
```

Full reset (also removes custom images):
```bash
make fclean
```

Rebuild from clean state:
```bash
make re
```

Inspect volumes:
```bash
docker volume ls
docker volume inspect db_volume
docker volume inspect wp_volume
```

Inspect running containers:
```bash
docker ps
docker logs nginx
docker logs wordpress
docker logs mariadb
```

## 4. Data storage and persistence model
This project uses named Docker volumes with bind-style `driver_opts`.

Data locations on host:
- MariaDB data: `/home/sanferna/data/mariadb`
- WordPress files/data: `/home/sanferna/data/wordpress`

Persistence behavior:
- `make down` keeps data.
- `make clean` removes containers and volumes from Docker metadata, but host data folders can remain depending on local state.
- `make fclean` also removes images.

## 5. Port change procedure (important)
To change exposed HTTPS port correctly, you must update both Docker Compose and WordPress URL settings.

### Step A: Change host port exposure in Compose
In `srcs/docker-compose.yml`, edit the first number in the port mapping under `nginx`:

Example:
```yaml
ports:
  - "8443:443"
```

- `8443` = host port (outside)
- `443` = container Nginx port (inside)

### Step B: Make WordPress use the same public URL (with port)
If WordPress URL does not include the new port, redirects/login flows can point to the old URL and appear broken.

#### Case 1: Fresh deployment (before first install)
Set `DOMAIN_NAME` in `srcs/.env` including the port:
```env
DOMAIN_NAME=sanferna.42.fr:8443
```
Then run:
```bash
make clean
make up
```

#### Case 2: Existing deployment (already initialized)
WordPress stores `home` and `siteurl` in the database, so update both values:

```bash
docker compose -f srcs/docker-compose.yml --env-file srcs/.env exec wordpress \
  wp option update home "https://sanferna.42.fr:8443" --allow-root --path=/var/www/html

docker compose -f srcs/docker-compose.yml --env-file srcs/.env exec wordpress \
  wp option update siteurl "https://sanferna.42.fr:8443" --allow-root --path=/var/www/html
```

After updating, verify in browser:
- `https://sanferna.42.fr:8443`
- `https://sanferna.42.fr:8443/wp-admin`

## 6. Service-level quick checks for developers
Container state:
```bash
make ps
```

TLS endpoint:
```bash
curl -kI https://sanferna.42.fr
```

Admin endpoint:
- Open `/wp-admin` and confirm login page loads.

If something fails:
```bash
make logs
```
