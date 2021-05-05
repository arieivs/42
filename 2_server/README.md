# ft_server
How to navigate the stormy waters of Docker 🌊
If you are new to Docker and containers, here are my suggestions:

<br />

## 📦 Learn about Containers
Watch [Network Chuck's video on Docker 101](https://www.youtube.com/watch?v=eGz9DS-aIeY) and [IBM's video on Containers vs Virtual Machines](https://www.youtube.com/watch?v=0qotVMX-J5s).

<br />

## 💻 Install Docker
At school: install Docker via the Managed Software Center.
Clone the [42toolbox](https://github.com/alexandregv/42toolbox) and run the init_docker.sh script.

Open the application and once it is up and running, try the following command: ```docker run hello-world```.
If you get an error saying your Docker daemon isn't running, [try this](https://pitman.io/posts/fix-docker-wont-start-error-on-mac-os/).

<br />

## 🐳 Get familiar with Docker
Get comfortable with Docker's terminology and play around with existing docker images before starting to create your own.
* Watch [Get started with Docker](https://docs.docker.com/get-started/)
* Follow the [Docker curriculum](https://docker-curriculum.com/#setting-up-your-computer) tutorial
* Explore [vvarodi's Github](https://github.com/vvarodi/ft_server)

<br />

## 📄 Create your Dockerfile
What is your Dockerfile supposed to do?
1. Install the base image, Debian Buster, and update its software packages
2. Install Nginx, MariaDB, PHP, Wget
3. Replace the default Nginx config file by your own
4. Install PHPMyAdmin with Wget and replace its config file for your own
5. Install WordPress with Wget and replace its config file for your own
6. Set the SSL Certificate
7. Change web files owner
8. Run initialising script

Check the [Dockerfile reference](https://docs.docker.com/engine/reference/builder/) and [Dockerfile best practices](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/) to get familiar with the syntax.

### NGINX
Once you run a container with Nginx installed, run ```cat etc/nginx/sites-available/default```.
That file has some guidelines on how to personalise it, follow them along with [this article](https://forhjy.medium.com/how-to-install-lemp-wordpress-on-debian-buster-by-using-dockerfile-1-75ddf3ede861).

### PHPMyAdmin
Once you run a container with PHPMyAdmin installed, ```cat var/www/html/phpmyadmin/config.sample.inc.php```.
Once again you will have to create your own ```config.inc.php```, follow its guidelines and [this article](https://forhjy.medium.com/42-ft-server-how-to-install-lemp-wordpress-on-debian-buster-by-using-dockerfile-2-4042adb2ab2c).

### WordPress
Sing with me, "Once you run a container with WordPress installed", ```cat var/www/html/wordpress/wp-config-sample.php``` and create your ```wp-config.php```.

### SSL Certificate
The purpose is to generate a self-signed certificate.
If you run ```openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt``` inside the container, it will ask you information on your location, in order to generate the SSL key.
Only the country two letter code is strictly necessary, you can enter '.' in the remaining fields, which will be left blank.
To do this automatically, add ```-subj "/C=PT/ST=./L=./O=./OU=./CN=."``` (in my case, since I'm in Portugal) before ```-newkey```.
Check in [this article](https://velog.io/@ljiwoo59/ftserver#wordpress) the meaning of the first command above.
Once the key has been created, a message will appear saying its location. Look for the location of the certificate, most probably in ```etc/ssl/certs```, and update both of them in your Nginx config file.

### Change web files owner
At this point, the owner and user-group from your web files is root. Try ```ls -l var/www/html``` to check this.
At the same time, Nginx's process owner is www-data (the default). Try ```cat etc/nginx/nginx.conf``` and look at the user to check this.
You can read more about the [www-data user here](https://askubuntu.com/questions/873839/what-is-the-www-data-user), and get a better understanding on [users, user-groups and chown here](https://askubuntu.com/questions/950196/www-data-related-whats-the-difference-between-these-usages-of-chown).

<br />

## 🐚 Create your initialising script
There are some additional shell commands you need in order to run your server. Namely:
1. Start Nginx, MySQL and PHP services
2. Configure a database for WordPress

### Set up a Database
Once you run a container with MariaDB installed, run ```service mysql start``` followed by ```mysql -u root --skip-password``` (to open the MariaDB monitor as the root user) or simply ```mysql```.
Play around with the commands at [vvarodi's init script](https://github.com/vvarodi/ft_server/blob/master/ft_server/srcs/start.sh) and check [this article](https://forhjy.medium.com/42-ft-server-how-to-install-lemp-wordpress-on-debian-buster-by-using-dockerfile-2-4042adb2ab2c) to understand their purpose.

<br />

## ♾ Keep it running!
Containers are automatically exited once you finish performing all operations.
However, you want it to keep running until you tell it otherwise.
From what I've understood there's at least three ways you can do that:
1. Run ```echo "daemon off;" >> /etc/nginx/nginx.conf``` in your Dockerfile. This will ensure Nginx stays in the foreground.
2. Add ```bash``` at the end of your init script: this will tell Docker there are still things to be done, so he will keep on waiting for new commands
3. Create an infinite loop at the end of your init script
