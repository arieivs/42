FROM	debian:buster

RUN		apt-get update
RUN		apt-get upgrade -y

RUN		apt-get -y install wget

RUN		apt-get -y install nginx
docker built -t nginx
docker run -it -p 80:80 nginx
