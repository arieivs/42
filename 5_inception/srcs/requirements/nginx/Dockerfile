# DOCKERFILE 🐳 for NGINX ​⚙️​

# Install base image, Debian buster, and update its packages
# the -y flag is for auto "Yes"
FROM	debian:buster

RUN 	apt-get update
RUN 	apt-get upgrade -y

# Install Nginx
RUN 	apt-get -y install nginx

# keep Nginx running in the foreground
RUN 	echo "daemon off;" >> /etc/nginx/nginx.conf

# do I need to replace default config files with my own?

# SSL - generate a self-signed certificate
RUN 	openssl req -x509 -nodes -days 365 -subj "/C=PT/ST=./L=./O=./OU=./CN=." -newkey rsa:2048 -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt

# Giving nginx's user-group rights over website files? Maybe in WP dockerfile...

# Copy stuff?
# entrypoint?