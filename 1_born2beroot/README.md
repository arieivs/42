# Born2BeRoot
Welcome to the Matrix 😎

<br />

## 🤔 What are Virtual Machines?
Watch [NetworkChuck's video on Virtual Machines](https://www.youtube.com/watch?v=wX75Z-4MEoM).

<br />

## 📦 Using VirtualBox at school
Install VirtualBox via the Managed Software Center.
On VirtualBox settings, move the default folder "VirtualBox VMs" into sgoinfre/user_name to avoid storage issues (you can access this folder from any of the school's computers).

<br />

## 💡 Concepts
**Package manager** is a collection of software tools that automates the process of installing, upgrading, configuring and removing computer programmes in a consistent manner (shamelessly copied from Wikipedia).

**APT (Advanced Package Tool)** and **Aptitude** are both package managers for Debian OS.
APT has only a CLI, while Aptitude offers a GUI (and some other additional features).
Learn more about [apt vs aptitude](https://askubuntu.com/questions/347898/whats-difference-of-apt-get-and-aptitude), [these vs dpkg](https://askubuntu.com/questions/309113/what-is-the-difference-between-dpkg-and-aptitude-apt-get), [wajig and apt-get's easter egg](https://unix.stackexchange.com/questions/767/what-is-the-real-difference-between-apt-get-and-aptitude-how-about-wajig). 

**AppArmor** and **SELinux** (Security-Enhanced Linux) are both independent Linux Security Modules.
They both control who can and cannot access certain files or directories, protecting the OS and other applications from both external and internal threats.
"SELinux controls access based on the labels of the files and processes while AppArmor controls access based on the paths of the program files." (from [this article on AppArmor vs SELinux](https://www.omarine.org/blog/apparmor-vs-selinux/))

**SSH (Secure Shell) Protocol** read more about this toooo: https://www.youtube.com/watch?v=ORcvSkgdA58

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

Some guidance: inside your VM running in Linux and when looking at your VM's settings on VirtualBox, GB/MB is actually GiB/MiB. When you're creating your VM and defining partitions sizes, it's GB/MB.

<br />

## 🌱 Born to be Root
Follow [Antonio's amazing notes](https://www.notion.so/Born2BeRoot-6a10c2b772a74c20981c1c16b961b404) - that's basically what you need to do.
Some additional notes below:

### 1. Create a new Virtual Machine
* Create a new VM (with Debian 64-bit) and go for all recommended options;
* VM size: if you're aiming for the bonus, choose 30.8 GB else keep it at 8GB;
* The size should be [divisible by 512 bytes](https://www.virtualbox.org/ticket/18177) - use the slider;
* Host key: shortcut which allows you to getting out of the virtual machine when it's capturing your mouse and keyboard (it appears on the right-bottom corner of the window);
* No GUI is allowed, so you cannot choose Graphical Install - choose just Install (confirm!!).

<br />

### 2. Partitions & LVM
Mandatory part:
* Guided partitioning with encrypted LVM;
* Separate /home partition;
* Logical: 7.5 GiB = 8GB.

Bonus:
* Manual;
* Select your disk/device to create a new partitions table, and then select the generated free space;
* Primary: 500 MiB = 524.3 MB, Mount point: boot, bootable flag on;
* Logical: 30.3 GiB = 32.2 GB;
  * Root: 10 GiB = 10.7 GB, file system ext4;
  * Swap: 2.3 GiB = 2.15 GB, swap area;
  * Home: 5 GiB = 5.4 GB, file system ext4;
  * var, srv, tmp: 3 GiB = 3.2 GB;
  * var-log: 4 GiB = 4.3 GB;
* A note on naming logical volumes: - (dashes) will double.

#### 💡 Partitions
Learn about [partitions and why they come in handy](https://www.howtogeek.com/184659/beginner-geek-hard-disk-partitions-explained/).
There are different kinds of partitions: primary, extended and logical.
Primary partitions are bootable, and contain the Operating System.
An extended partition is basically a defined area were logical partitions reside.
There is a limit to the number of primary partitions allowed in a single machine, while you can have as many logical partitions as you want.
Learn more about [primary and logical partitions here](https://www.differencebetween.com/difference-between-primary-partition-and-vs-logical-partition/).

#### ❔ Why sda?
sda refers to the first sd, which stands for SCSI (Small Computer System Interface) disk.
Learn more about [/dev/sda here](https://www.tec4tric.com/linux/dev-sda-in-linux).

#### 📂 File Systems
Learn more about the different [file systems and their compatibility with different OS here](https://www.youtube.com/watch?v=_h30HBYxtws).
For Linux, the most common one is ext4.

#### 🔀 Swap
Swap area is used to keep your applications running when you run out of RAM.
In other words, is a fake RAM that resides in your hard-drive.
Learn more on [Swap area here](https://askubuntu.com/questions/508870/what-is-a-swap-area).

<br />

### 3. Finish Installation
* Installing GRUB boot loader? Yes.

#### 💡 Package managers: APT vs Aptitude
**Package manager** is a collection of software tools that automates the process of installing, upgrading, configuring and removing computer programmes in a consistent manner (shamelessly copied from Wikipedia).
**APT (Advanced Package Tool)** and **Aptitude** are both package managers for Debian OS.
APT only has a CLI, while Aptitude offers a GUI (and some other additional features).
Learn more about [apt vs aptitude](https://askubuntu.com/questions/347898/whats-difference-of-apt-get-and-aptitude), [these vs dpkg](https://askubuntu.com/questions/309113/what-is-the-difference-between-dpkg-and-aptitude-apt-get), [wajig and apt-get's easter egg](https://unix.stackexchange.com/questions/767/what-is-the-real-difference-between-apt-get-and-aptitude-how-about-wajig).

#### 🌫 Mirrors & CDN
what are they?

#### GRUB boot loader
what is grub boot loader?

<br />

### Extra: Fixing partitions sizes
Your partitions are not quite the way you wanted?
My advice: leave it.
Still want to fix it?
Use ```fdisk```:

```su```    to login as root

```umount /dev/sdaX```    unmount the partition sdaX

```/sbin/fdisk /dev/sda```   in case [sbin is not in your PATH](https://unix.stackexchange.com/questions/577050/bash-fdisk-command-not-found)

```Command: d```    and then choose the partition number to delete

```Command: n```    create new, Last sector: +size{unit}

Watch out for empty space: you will obviously need to free space in order to increase a partition's size. Save the new partition and...

```mount /dev/sdaX```  mount it

<br />

### 4. AppArmor
#### 🔐 AppArmor vs SELinux
**AppArmor** and **SELinux** (Security-Enhanced Linux) are both independent Linux Security Modules.
They both control who can and cannot access certain files or directories, protecting the OS and other applications from both external and internal threats.
"SELinux controls access based on the labels of the files and processes while AppArmor controls access based on the paths of the program files." (from [this article on AppArmor vs SELinux](https://www.omarine.org/blog/apparmor-vs-selinux/))


This ReadMe is under construction!

Happy virtualisation! 👻
