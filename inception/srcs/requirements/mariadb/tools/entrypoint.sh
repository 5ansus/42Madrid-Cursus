#!/bin/sh
set -eu

DB_PASSWORD="$(cat "$MYSQL_PASSWORD_FILE")"
DB_ROOT_PASSWORD="$(cat "$MYSQL_ROOT_PASSWORD_FILE")"

mkdir -p /run/mysqld
chown -R mysql:mysql /run/mysqld /var/lib/mysql

if [ ! -d /var/lib/mysql/mysql ]; then
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql >/dev/null
fi

/usr/sbin/mysqld --user=mysql --skip-networking --socket=/run/mysqld/mysqld.sock &
MYSQLD_PID=$!

TRIES=0
until mysqladmin --socket=/run/mysqld/mysqld.sock ping >/dev/null 2>&1; do
    TRIES=$((TRIES + 1))
    if [ "$TRIES" -gt 60 ]; then
        echo "MariaDB init timeout"
        kill "$MYSQLD_PID" || true
        exit 1
    fi
    sleep 1
done

mysql mysql --protocol=socket --socket=/run/mysqld/mysqld.sock -uroot -p"${DB_ROOT_PASSWORD}" <<-EOSQL
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
    CREATE DATABASE IF NOT EXISTS \`${MYSQL_DATABASE}\`;
    CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
    GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO '${MYSQL_USER}'@'%';
    FLUSH PRIVILEGES;
EOSQL

mysqladmin --socket=/run/mysqld/mysqld.sock -uroot -p"${DB_ROOT_PASSWORD}" shutdown

exec "$@"
