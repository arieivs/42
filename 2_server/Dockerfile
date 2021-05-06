# Install base image, Debian buster, and update its packages
# the -y flag is for auto "Yes"
FROM	debian:buster

RUN		apt-get update
RUN		apt-get upgrade -y

# Install Nginx, MariaDB, PHP and Wget
# php-fpm: fastCGI PHP processing manager
# php-mysql: allowing PHP to communicate with the MySQL database
# php-mbstring: manages non-ASCII strings
RUN		apt-get -y install nginx mariadb-server php-fpm php-mysql php-mbstring wget

# NGINX
# keep Nginx running in the foreground
RUN		echo "daemon off;" >> /etc/nginx/nginx.conf
# remove default index page
RUN		rm var/www/html/index.nginx-debian.html
# replace default config file
COPY	srcs/nginx.conf /etc/nginx/sites-available/default

# PHPMyAdmin
# install it using Wget
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.2/phpMyAdmin-5.0.2-english.tar.gz && \
    	tar -xzvf phpMyAdmin-5.0.2-english.tar.gz && \
    	rm -rf phpMyAdmin-5.0.2-english.tar.gz && \
    	mv phpMyAdmin-5.0.2-english/ /var/www/html/phpmyadmin
# replace default config file
COPY	srcs/config.inc.php /var/www/html/phpmyadmin

# WordPress
# install it using Wget
RUN		wget https://wordpress.org/latest.tar.gz && \
    	tar -xzvf latest.tar.gz && \
    	rm -rf latest.tar.gz && \
    	mv wordpress /var/www/html/
# replace default config file
COPY	srcs/wp-config.php /var/www/html/wordpress

# SSL
# generate a self-signed certificate
RUN		openssl req -x509 -nodes -days 365 -subj "/C=PT/ST=./L=./O=./OU=./CN=." -newkey rsa:2048 -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt

# Giving nginx's user-group rights over website files
RUN	chown -R www-data:www-data /var/www/html/*

# Bring in your bash scripts and run init
COPY	srcs/*.sh ./
CMD		bash init.sh
