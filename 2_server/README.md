# ft_server
How to navigate the stormy waters of Docker 🌊
If you are new to Docker and containers, here are my suggestions:

## 📦 Learn about Containers
Watch [Network Chuck's video on Docker 101](https://www.youtube.com/watch?v=eGz9DS-aIeY) and [IBM's video on Containers vs Virtual Machines](https://www.youtube.com/watch?v=0qotVMX-J5s).

## 💻 Install Docker
At school: install Docker via the Managed Software Center.
Clone the [42toolbox](https://github.com/alexandregv/42toolbox) and run the init_docker.sh script.

Open the application and once it is up and running, try the following command: ```docker run hello-world```.
If you get an error saying your Docker daemon isn't running, [try this](https://pitman.io/posts/fix-docker-wont-start-error-on-mac-os/).

## 🐳 Get familiar with Docker
Get comfortable with Docker's terminology and play around with existing docker images before starting to create your own.
* Watch [Get started with Docker](https://docs.docker.com/get-started/)
* Follow the [Docker curriculum](https://docker-curriculum.com/#setting-up-your-computer) tutorial
* Explore [vvarodi's Github](https://github.com/vvarodi/ft_server)

## 📄 Create your Dockerfile
What is your Dockerfile supposed to do?
1. Install the base image, Debian Buster, and update its software packages
2. Install Nginx, MariaDB, PHP, Wget
3. Replace the default Nginx config file by your own (we'll get there)

### NGINX
Once you run a container with Nginx installed, run ```cat etc/nginx/sites-available/default```. That file has some guidelines on how to personalise your own (note that your own config file will be inside the srcs directory). Follow [this article](https://forhjy.medium.com/how-to-install-lemp-wordpress-on-debian-buster-by-using-dockerfile-1-75ddf3ede861) on how to personalise it.


## 🐚 Create your init script
There are some shell commands you need in order to run your container. Namely:
1. Start Nginx, MySQL and PHP services
2. Configure a database for WordPress
3. ???

### Set up a Database
Once you run a container with MariaDB installed, run ```service mysql start``` followed ```mysql```
