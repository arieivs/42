# Born2BeRoot
Welcome to the Matrix 😎

<br />

## 🤔 What are Virtual Machines?
Watch [NetworkChuck's video on Virtual Machines](https://www.youtube.com/watch?v=wX75Z-4MEoM).

<br />

## 💡 Concepts
**Package manager** is a collection of software tools that automates the process of installing, upgrading, configuring and removing computer programmes in a consistent manner (shamelessly copied from Wikipedia).

**APT (Advanced Package Tool)** and **Aptitude** are both package managers for Debian OS.
APT has only a CLI, while Aptitude offers a GUI (and some other additional features).
Learn more about [apt vs aptitude](https://askubuntu.com/questions/347898/whats-difference-of-apt-get-and-aptitude), [these vs dpkg](https://askubuntu.com/questions/309113/what-is-the-difference-between-dpkg-and-aptitude-apt-get), [wajig and apt-get's easter egg](https://unix.stackexchange.com/questions/767/what-is-the-real-difference-between-apt-get-and-aptitude-how-about-wajig). 

**AppArmor** and **SELinux** (Security-Enhanced Linux) are both independent Linux Security Modules.
They both control who can and cannot access certain files or directories, protecting the OS and other applications from both external and internal threats.
"SELinux controls access based on the labels of the files and processes while AppArmor controls access based on the paths of the program files." (from [this article on AppArmor vs SELinux](https://www.omarine.org/blog/apparmor-vs-selinux/))

more things related to Debian I should be aware of?

**SSH (Secure Shell) Protocol** read more about this toooo 

**UFW** stands for Uncomplicated Firewall

kinds of files you can use for the new virtual hard disk: VDI (VirtualBox Disk Image, what we are using), VHD (Virtual Hard Disk), VMDK (Virtual Machine Disk).

iptables???

<br />

## 📏 GB or GiB? Figure out your Units!
What would be science without some units conversion issues?
Learn about [decimal vs IEC](https://linuxreviews.org/Multiples_of_bytes).
So when you see GB/MB, you have to figure out if it's really GB/MB or if it's actually GiB/MiB.
That's the tricky part.
And that's on you.
Some guidance: inside your VM running in Linux and when looking at your VM's settings at VirtualBox, GB/MB is actually GiB/MiB. When you're creating your VM and defining partitions sizes, it's GB/MB.

<br />

## 📦 Using VirtualBox at school
Install VirtualBox via the Managed Software Center.
On VirtualBox settings, move the default folder "VirtualBox VMs" into sgoinfre/user_name to avoid storage issues (you can access this folder from any of the school's computers).

<br />

## 🌱 Born to be Root
Follow [Antonio's amazing notes](https://www.notion.so/Born2BeRoot-6a10c2b772a74c20981c1c16b961b404) - that's basically what you need to do.
Some additional notes below:

### 1. Create a new Virtual Machine
* Create a new VM (with Debian 64-bit) and go for all recommended options;
* VM size: if you're aiming for the bonus, choose 30.8 GB else keep it at 8GB;
* Host key: shortcut which allows you to getting out of the virtual machine when it's capturing your mouse and keyboard (it appears on the right-bottom corner of the window);
* No GUI is allowed, so you cannot choose Graphical Install - choose just Install (confirm!!).

### 2. Partitions & LVM
* Select your disk/device to create a new partitions table, and then select the generated free space;
* Total: 8 GiB = 8.6 GB;
* Primary(boot): 487 MiB = 510.7 MB, Mount point: boot, bootable flag on;
* Note: round the size to tenths and not hundredths (so 510.7 instead of 510.66) or it will change your value; -> more complex!!
* Logical: 7.5 GiB = 8 GB;
* Root: 2.8 GiB = 3 GB;
* Home: 3.8 GiB = 4 GB;
Primary partition vs logical - search

[sda](https://www.tec4tric.com/linux/dev-sda-in-linux)

usage of partitions in real life: for boot and recovery? not much more? check it outtttt

file system: the most common one is Ext4
swap area is the swap file system

mirror similar to CDN

This ReadMe is under construction!

Happy virtualisation! 👻
