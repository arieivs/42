# Install base image, Debian buster, and update its packages
# the -y flag is for auto "Yes"
FROM	debian:buster

RUN		apt-get update
RUN		apt-get upgrade -y

# Install Nginx, MariaDB, PHP and Wget
RUN		apt-get -y install nginx mariadb-server php-fpm php-mysql php-mbstring wget

# NGINX - Replace default config file with ours
# should I care about daemon off?
COPY	srcs/nginx/*.conf /etc/nginx/sites-available/default;

# PHPMyAdmin
