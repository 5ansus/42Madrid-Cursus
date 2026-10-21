*This project has been created as part of the 42 curriculum by sanferna*

# Inception

## Description
Inception is a containerized web infrastructure project from 42. Its main goal is to learn Docker by building a small production-like stack where each service is isolated, reproducible, and connected through a controlled network.

This repository deploys a full WordPress website over HTTPS using three dedicated services:
- MariaDB for persistent relational data.
- WordPress (PHP-FPM) for application logic.
- Nginx for TLS termination and HTTP serving.

### Why Docker in this project
Docker is used to package each service with only the dependencies it needs, then orchestrate all services with Docker Compose. This provides:
- Isolation between services.
- Reproducible environments.
- Easier lifecycle management (build, start, stop, cleanup).

### Project sources and structure
- `Makefile`: main entry point to build, run, stop, and clean the stack.
- `srcs/docker-compose.yml`: service orchestration, network, volumes, secrets, and published ports.
- `srcs/.env`: non-sensitive runtime configuration (domain, usernames, emails, service variables).
- `srcs/requirements/mariadb`: MariaDB image, config, and bootstrap script.
- `srcs/requirements/wordpress`: WordPress/PHP-FPM image, config, and bootstrap script.
- `srcs/requirements/nginx`: Nginx image, TLS config, and bootstrap script.
- `secrets/*.txt`: local secret files consumed by Docker secrets.
- `secrets/*.txt.example`: templates showing required secret files.

### Main design choices
- One process per containerized service (MariaDB, WordPress/PHP-FPM, Nginx).
- Internal bridge network for inter-service communication and DNS by service name.
- Docker secrets (file-backed) for passwords instead of plain environment variables.
- Persistent storage through host-backed named volumes.
- HTTPS exposed by Nginx on port 443 with a self-signed certificate generated at startup.

### Required technical comparisons
#### Virtual Machines vs Docker
- A virtual machine runs a full guest OS on a hypervisor, which increases startup time and resource usage.
- Docker containers share the host kernel and package only app + dependencies, so they are lighter and faster to start.
- For this project, Docker enables quick rebuilds and predictable local environments without managing full guest systems.

#### Secrets vs Environment Variables
- Environment variables are convenient, but credentials may be easier to expose through process inspection, logs, or debugging output.
- Docker secrets are mounted as files and read at runtime, reducing accidental exposure in compose files and shell history.
- In this stack, database and WordPress passwords are read from files in `/run/secrets/...`.

#### Docker Network vs Host Network
- Host network mode removes network namespace isolation and shares the host network stack directly.
- Docker bridge networks isolate container traffic while still allowing published ports for controlled external access.
- This project uses a custom bridge network so containers resolve each other by service name (for example, `wordpress` and `mariadb`) and only Nginx exposes port 443 to the host.

#### Docker Volumes vs Bind Mounts
- Docker volumes are managed by Docker, easier to migrate between hosts, and less coupled to a specific folder layout.
- Bind mounts map an explicit host path, which gives direct visibility and control but creates stronger coupling to host paths and permissions.
- This project uses named volumes with bind-style `driver_opts` to persist data in fixed host folders (`/home/sanferna/data/...`).

## Instructions
### Prerequisites
- Linux VM or host with:
  - Docker Engine
  - Docker Compose (v2)
  - GNU Make
- Internet access (WordPress CLI and package download happen during first bootstrap).
- Optional but recommended for remote VM workflows:
  - SSH
  - SCP

Important constraint:
- This repository currently uses hardcoded host paths under `/home/sanferna` in the Makefile and compose volume configuration.
- If your Linux user is not `sanferna`, update those paths before running the stack.

### 1. Get the project onto your machine
If you work on a VM and copy from another machine, one possible SCP workflow is:

```bash
scp -P 2222 -r <local-project-folder> sanferna@127.0.0.1:/home/sanferna/
```

Then enter the project directory:

```bash
cd /home/sanferna/inception
```

### 2. Configure secrets
Create real secret files from the templates in `secrets/`:
- `db_password.txt`
- `db_root_password.txt`
- `wp_admin_password.txt`
- `wp_user_password.txt`

Each file must contain only the password value (single line).

### 3. Ensure domain resolution for local testing
The WordPress install URL is based on `DOMAIN_NAME=sanferna.42.fr`.
Add a host mapping on the machine that opens the browser:

```bash
sudo sh -c 'echo "127.0.0.1 sanferna.42.fr" >> /etc/hosts'
```

If Docker runs in a remote VM, map `sanferna.42.fr` to the VM IP instead of `127.0.0.1`.

### 4. Build and start
From the repository root:

```bash
make up
```

This creates data directories, builds images, and starts containers in detached mode.

### 5. Access the website and admin panel
- Website: `https://sanferna.42.fr`
- Admin panel: `https://sanferna.42.fr/wp-admin`

Notes:
- A self-signed certificate is generated automatically, so browser security warnings are expected.
- On first run, initialization can take some time while database and WordPress bootstrap complete.

### Optional SSH tunnel workflow
If you browse from outside the VM, a SOCKS tunnel is one valid option:

```bash
ssh -N -v -p 2222 -D 127.0.0.1:1080 sanferna@127.0.0.1
```

Then configure your browser to use SOCKS proxy `127.0.0.1:1080`.

### 6. Useful lifecycle commands
```bash
make ps       # show running services
make logs     # follow logs
make down     # stop containers
make clean    # stop and remove containers + volumes
make fclean   # clean + remove images
make re       # full rebuild
```

## Resources
### Learning references
- https://devabdilah.medium.com/inception-42-a-comprehensive-guide-to-dockerizing-your-first-infrastructure-part-i-bd7d4bdc13e6
- https://devabdilah.medium.com/inception-42-a-comprehensive-guide-to-dockerizing-your-first-infrastructure-part-ii-bed64a739bf4
- https://devabdilah.medium.com/inception-42-a-comprehensive-guide-to-dockerizing-your-first-infrastructure-part-iii-a10e93e9d922

### Code references used for comparison
- https://github.com/gemartin99/Inception/tree/main
- https://github.com/amsteradri/Inception

### AI usage disclosure
AI tools (GitHub Copilot and ChatGPT) were used for:
- Clarifying Docker and Compose concepts during development.
- Troubleshooting specific script and configuration issues.
- Improving technical writing quality for project documentation.

All architecture and implementation decisions were validated against the project files in this repository.
