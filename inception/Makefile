NAME=inception
COMPOSE_FILE=srcs/docker-compose.yml
ENV_FILE=srcs/.env
DOCKER_COMPOSE=docker compose -f $(COMPOSE_FILE) --env-file $(ENV_FILE)

all: up

build:
	@mkdir -p /home/sanferna/data/mariadb /home/sanferna/data/wordpress
	$(DOCKER_COMPOSE) build

up: build
	$(DOCKER_COMPOSE) up -d

down:
	$(DOCKER_COMPOSE) down

restart: down up

logs:
	$(DOCKER_COMPOSE) logs -f

ps:
	$(DOCKER_COMPOSE) ps

clean:
	$(DOCKER_COMPOSE) down -v

fclean: clean
	docker image rm -f mariadb wordpress nginx 2>/dev/null || true

re: fclean up

.PHONY: all build up down restart logs ps clean fclean re host
