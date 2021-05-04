# Install base image, Debian buster, and update its packages
# the -y flag is for auto "Yes"
FROM	debian:buster

RUN		apt-get update
RUN		apt-get upgrade -y

# Install Nginx, MariaDB, PHP and Wget
RUN		apt-get -y install nginx mariadb-server php-fpm php-mysql php-mbstring wget

# NGINX
# keep Nginx running in the foreground
RUN		echo "daemon off;" >> /etc/nginx/nginx.conf
# replace default config file with mine
COPY	srcs/nginx.conf /etc/nginx/sites-available/default

# PHPMyAdmin
# install it using Wget
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz && \
    	tar -xzvf phpMyAdmin-5.0.2-english.tar.gz && \
    	rm -rf phpMyAdmin-5.0.2-english.tar.gz && \
    	mv phpMyAdmin-5.0.2-english/ /var/www/html/phpmyadmin
# replace default config file with mine
COPY	srcs/config.sample.inc.php /var/www/html/phpmyadmin
