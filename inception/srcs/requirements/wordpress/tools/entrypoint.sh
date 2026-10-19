#!/bin/sh
set -eu

WP_DB_PASSWORD="$(cat "$WP_DB_PASSWORD_FILE")"
WP_ADMIN_PASSWORD="$(cat "$WP_ADMIN_PASSWORD_FILE")"
WP_USER_PASSWORD="$(cat "$WP_USER_PASSWORD_FILE")"

mkdir -p /run/php /var/www/html
chown -R www-data:www-data /var/www/html

if [ ! -f /var/www/html/wp-config.php ]; then
    wp core download --allow-root --path=/var/www/html

    TRIES=0
    until mysqladmin ping -h"${WP_DB_HOST%%:*}" -u"$WP_DB_USER" -p"$WP_DB_PASSWORD" >/dev/null 2>&1; do
        TRIES=$((TRIES + 1))
        if [ "$TRIES" -gt 60 ]; then
            echo "WordPress DB wait timeout"
            exit 1
        fi
        sleep 1
    done

    wp config create \
        --allow-root \
        --path=/var/www/html \
        --dbname="$WP_DB_NAME" \
        --dbuser="$WP_DB_USER" \
        --dbpass="$WP_DB_PASSWORD" \
        --dbhost="$WP_DB_HOST"

    wp core install \
        --allow-root \
        --path=/var/www/html \
        --url="https://${DOMAIN_NAME}" \
        --title="$WP_TITLE" \
        --admin_user="$WP_ADMIN_USER" \
        --admin_password="$WP_ADMIN_PASSWORD" \
        --admin_email="$WP_ADMIN_EMAIL"

    wp user create "$WP_USER" "$WP_USER_EMAIL" \
        --allow-root \
        --path=/var/www/html \
        --role=author \
        --user_pass="$WP_USER_PASSWORD"
fi

exec "$@"
