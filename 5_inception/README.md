# Inception
Get to the next level with docker containers 

<br/>

## 🔗​ Useful Resources
* Docker documentation
* Digital Ocean tutorials
* [Przemek's Inception Readme](https://github.com/psleziak42/inception_docker)
* [Inception Guide (without volumes)](https://github.com/NEKuipers/Inception/blob/master/Inception_guide.txt)

<br/>

## ​🖥️​ Virtual Machine
Make sure to move VirtualBox default folder to sgoinfre at school.

I chose to use the same OS as our computers at school, [Ubuntu Focal 20.04](https://releases.ubuntu.com/focal/).
The important thing is to choose a disk image with a GUI (so that you can open the web browser and check your website) and that fulfills [docker's OS requirements](https://docs.docker.com/engine/install/).
Make sure to move the disk image to sgoinfre, or you'll run out of space.

It's advised to choose 2GB of RAM so that your machine is not too slow.
Memory-wise, you will need 8.6GB just for installing this ubuntu version.
Consider that docker, the docker images and containers will all take quite some space...

​⚠️​ TODO Check in the end how much space is actually needed;
currently with 20 GB for memory disk.

Next up, [install docker](https://docs.docker.com/engine/install/ubuntu/) (docker compose plugin comes along).

Setting up a shared folder to access your project repository will make things easier.
To do that, in VirtualBox go to Settings > Shared, and add the folder you want to share (here referred to as <computer_folder>).
Set it to auto mount, permanent, and click OK.
Inside your virtual machine, create a new folder (here referred to as <vm_folder>).
Then run the following command:
```
sudo mount -t vboxsf <computer_folder> <vm_folder>
```

<br/>

## ​​🐋​ Docker compose
The [docker compose documentation](https://docs.docker.com/compose/compose-file/) is your best friend.

​⚠️ Important: docker-compose.yml doesn't like tabs! Use spaces for identation.

<br/>

## ​​🐳​ Dockerfiles
Check ft_server

Reviewing some useful Docker commands:
```
docker images
docker ps --all
docker build . -t <image_name>
docker run --name <container_name> -d -p 80:80 -p 443:443 <image_name>
docker exec -it <container_name> bash
docker start <container_id>
docker stop <container_id>
docker rm <container_id>
docker rmi <image_id>
```
right now -p 443:443 doesnt work, need to understand the ports and ssl

<br/>

## To think/ Some collected thoughts
* network defined in docker-compose.yml
* dependencies in dockerfiles
* configuration in entrypoint.sh
* Makefile calls docker compose
* docker compose calls dockerfile
* dockerfile creates image and starts the container and runs all the config files
* 3306/tcp -> 127.0.0.1:3666 means port 3306 inside container is exposed on to port 3666 of host.

<br/>

Happy dockering! 🐳