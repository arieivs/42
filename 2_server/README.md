# ft_server
How to navigate the stormy waters of Docker 🌊
If you are new to Docker and containers, here are my suggestions:

<br />

## 📦 Learn about Containers
Watch [Network Chuck's video on Docker 101](https://www.youtube.com/watch?v=eGz9DS-aIeY) and [IBM's video on Containers vs Virtual Machines](https://www.youtube.com/watch?v=0qotVMX-J5s).

<br />

## ❓ What is... everything??
Let's try to give some meaning to some of the strange names mentioned in the subject:

**[Wget](https://www.gnu.org/software/wget/)**: allows you get files via the HTTP(S) and FTP(S) protocols - we will use it to get the necessary files for PHPMyAdmin and WordPress.

**[HTTP Server](https://medium.com/@gabriellamedas/the-http-server-explained-c41380307917)**: server software which receives requests and sends responses following the HTTP protocol.

**[Proxy Sever](https://www.varonis.com/blog/what-is-a-proxy-server/)**: (proxy is the authority to represent someone or do something on their behalf) a proxy server is an intermediate sever between the end-user/client and the sever where the website is hosted, so all traffic between these two flows through the proxy. The proxy server can be:
* Forward: on the client side
* Reverse: on the server side
There can be several advantages to using a proxy server, such as:
* Improved security and privacy, as it acts as a firewall
* Caches data to speed up common requests
* Control content (e.g.: don’t allow employees to go to social networks at work; parental control)

**[Nginx](https://nginx.org/en/)**: is both an HTTP and reverse proxy server. Another commonly used open source HTTP server is [Apache]( http://httpd.apache.org/).

**[MariaDB](https://www.guru99.com/mariadb-vs-mysql.html)**: is a variant from MySQL (a relational database management system).

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
1. Install the base image (Debian Buster) and update its software packages
2. Install Nginx, MariaDB, PHP, Wget
3. Replace the default Nginx config file for your own
4. Set the SSL Certificate
5. Install PHPMyAdmin and WordPress with Wget and replace their config files for your own
6. Change web files owner
7. Run initialising script

Check the [Dockerfile reference](https://docs.docker.com/engine/reference/builder/) and [Dockerfile best practices](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/) to get familiar with the syntax.

### NGINX
Once you run a container with Nginx installed, run ```cat etc/nginx/sites-available/default```.
That file has some guidelines on how to personalise it, follow them along with [this article](https://forhjy.medium.com/how-to-install-lemp-wordpress-on-debian-buster-by-using-dockerfile-1-75ddf3ede861).

### SSL Certificate
The purpose is to generate a self-signed certificate.
If you run ```openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/localhost.key -out /etc/ssl/certs/localhost.crt``` inside the container, it will ask you information on your location, in order to generate the SSL key.
Only the two-letter country code is strictly necessary, you can enter "." in the remaining fields, which will be left blank.
To do this automatically, add ```-subj "/C=PT/ST=./L=./O=./OU=./CN=."``` (in my case, since I'm in Portugal) before ```-newkey```.
Check in [this article](https://velog.io/@ljiwoo59/ftserver#wordpress) the meaning of the first command above.
Note that the key's and certificate's location is defined in the command above. Make sure it is consistent with what you wrote in your Nginx config file (and update it if necessary).

### PHPMyAdmin
Once you run a container with PHPMyAdmin installed, ```cat var/www/html/phpmyadmin/config.sample.inc.php```.
Once again you will have to create your own ```config.inc.php```, follow the guidelines and [this article](https://forhjy.medium.com/42-ft-server-how-to-install-lemp-wordpress-on-debian-buster-by-using-dockerfile-2-4042adb2ab2c).

### WordPress
Sing with me, "Once you run a container with WordPress installed", ```cat var/www/html/wordpress/wp-config-sample.php``` and create your own ```wp-config.php```.

### Change web files owner
At this point, the owner and user-group from your web files is root, you can check this by running ```ls -l var/www/html```.
This is not a very good idea from a security perspective... let's change it.
By default, Nginx's process owner is www-data, which makes it a good candidate.
Try ```cat etc/nginx/nginx.conf``` and look at the user to check this.
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

## 🏃‍♂️ Keep it runninggg...
Containers are automatically exited once you finish performing all operations.
However, you want to keep it running until you tell it otherwise.
There's at least three ways you can do that:
1. Run ```echo "daemon off;" >> /etc/nginx/nginx.conf``` in your Dockerfile. This will ensure Nginx stays in the foreground.
2. Add ```bash``` at the end of your init script: this will tell Docker there are still things to be done, so it will keep on waiting for new commands
3. Create an infinite loop at the end of your init script

<br />

## 📂 AutoIndex
There are still a few things to consider in order to change the autoindex while you are running your container:
1. Remove the default index page, ```index.nginx-debian.html```
2. Figure out how to change the ```autoindex on``` to ```autoindex off``` (and vice-versa) in the Nginx config file. I've seen three different approaches:
	* Create two separate Nginx files and copy only the appropriate one. An environment variable may come in handy (and a bash script)
	* Change the content of the Nginx file with a bash script
	* Install vim, open the Nginx file inside the container and change it 😆
3. Reload Nginx (restart it will close your container if you're keeping it open with "daemon off")

<br />

## ♾ Persistent Storage
This is a bonus!
Right now, every time you restart your container you lose everything.
This doesn't seem quite right for a website, does it? You want your storage to be persistent, not ephemeral!
In Docker this means Volumes.
Use them for both your MySQL and WordPress files.
Read more about [Volumes](https://docs.docker.com/storage/volumes/) and how to use [Volumes in the Dockerfile](https://docs.docker.com/engine/reference/builder/#volume).

<br />

## 🙌 Build and Run your Container!
```
docker build -t <image_name>
docker run --name <container_name> -d -p 80:80 -p 443:443
docker exec -it <container_name> bash
docker stop <container_name>
docker start <container_name>
```
<br />
Happy dockering! 🐳
