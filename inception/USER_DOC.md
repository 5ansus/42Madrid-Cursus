# USER_DOC

## 1. What this stack provides
This project runs a complete WordPress website on Docker with 3 services:
- `mariadb`: stores WordPress data (users, posts, settings).
- `wordpress`: runs PHP-FPM and the WordPress application.
- `nginx`: serves HTTPS traffic and forwards PHP requests to WordPress.

The public entry point is Nginx over HTTPS.

## 2. Start and stop the project
Run all commands from the repository root.

Start (build if needed):
```bash
make up
```

Check status:
```bash
make ps
```

See live logs:
```bash
make logs
```

Stop containers:
```bash
make down
```

Stop and remove containers + volumes:
```bash
make clean
```

Full reset (also removes custom images):
```bash
make fclean
```

## 3. Access the website and admin panel
Default project domain is `sanferna.42.fr`.

Website:
- `https://sanferna.42.fr`

Admin panel:
- `https://sanferna.42.fr/wp-admin`

Important:
- The certificate is self-signed, so your browser may show a warning.
- If needed, add a local hosts entry so the domain resolves correctly.

Example:
```bash
sudo sh -c 'echo "127.0.0.1 sanferna.42.fr" >> /etc/hosts'
```

## 4. Locate and manage credentials
Credentials are managed through Docker secrets in the `secrets/` folder.

Required secret files:
- `secrets/db_password.txt`
- `secrets/db_root_password.txt`
- `secrets/wp_admin_password.txt`
- `secrets/wp_user_password.txt`

How to manage them safely:
- Keep one password per file (single line).
- Do not commit real `.txt` secrets to git.
- Use the `.example` files as templates.
- After changing secrets on an existing deployment, run a clean rebuild:

```bash
make clean
make up
```

## 5. Check services are healthy
Quick checks:

1. Containers are up:
```bash
make ps
```
You should see `mariadb`, `wordpress`, and `nginx` running.

2. Nginx is reachable:
```bash
curl -kI https://sanferna.42.fr
```
You should get an HTTP response header.

3. Admin page responds:
- Open `https://sanferna.42.fr/wp-admin` in your browser.

4. Troubleshooting logs:
```bash
make logs
```
Look for errors from `nginx`, `wordpress`, or `mariadb`.

## 6. Notes for administrators
- Persistent data is stored on host paths under `/home/sanferna/data/`.
- If your Linux username is not `sanferna`, update host paths in the project before first launch.
