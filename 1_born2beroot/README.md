# Born2BeRoot
Welcome to the Matrix 😎

👉 Follow [António's amazing notes](https://www.notion.so/Born2BeRoot-6a10c2b772a74c20981c1c16b961b404) - that's basically what you need to do.
Some additional notes below:

<br />

## 🤔 What are Virtual Machines?
Watch [NetworkChuck's video on Virtual Machines](https://www.youtube.com/watch?v=wX75Z-4MEoM).

<br />

## 📦 Using VirtualBox at school
Install VirtualBox via the Managed Software Center.
On VirtualBox settings, move the default folder "VirtualBox VMs" into sgoinfre/user_name to avoid storage issues (you can access this folder from any of the school's computers).

<br />

## 📏 GB or GiB? Figure out your Units!
What would be science without some units conversion issues?
Learn about [decimal vs IEC](https://linuxreviews.org/Multiples_of_bytes).
So when you see GB/MB, you have to figure out if it's really GB/MB or if it's actually GiB/MiB.
That's the tricky part.
And that's on you.

Some guidance: inside your VM running in Linux and when looking at your VM's settings on VirtualBox, GB/MB is actually GiB/MiB. When you're creating your VM and defining partitions sizes, it's GB/MB.

<br />

## 1. Create a new Virtual Machine
* Create a new VM (with Debian 64-bit) and go for all recommended options;
* VM size: if you're aiming for the bonus, choose 30.8 GB else keep it at 8GB;
* The size should be [divisible by 512 bytes](https://www.virtualbox.org/ticket/18177) - use the slider;
* Host key: shortcut which allows you to getting out of the virtual machine when it's capturing your mouse and keyboard (it appears on the right-bottom corner of the window);
* No GUI is allowed, so you cannot choose Graphical Install - choose just Install (confirm!!).

### 💡 Debian vs Cent OS
Debian and Cent OS are both Linux distributions.
There are some differences between the two, for example they use different package managers and have different default filesystems.
Debian releases major updates more frequently (every two years compared with 10 years for Cent OS), which can be an advantage.
Finally, Cent OS set up can be trickier for newbies, so Debian might be a better first experience.
Learn [more here](https://www.openlogic.com/blog/centos-vs-debian).

<br />

## 2. Partitions & LVM
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

### 💡 Partitions
Learn about [partitions and why they come in handy](https://www.howtogeek.com/184659/beginner-geek-hard-disk-partitions-explained/).
There are different kinds of partitions: primary, extended and logical.
Primary partitions are bootable, and contain the Operating System.
An extended partition is basically a defined area were logical partitions reside.
There is a limit to the number of primary partitions allowed in a single machine, while you can have as many logical partitions as you want.
Learn more about [primary and logical partitions here](https://www.differencebetween.com/difference-between-primary-partition-and-vs-logical-partition/).

### ❔ Why sda?
sda refers to the first sd, which stands for SCSI (Small Computer System Interface) disk.
Learn more about [/dev/sda here](https://www.tec4tric.com/linux/dev-sda-in-linux).

### 📂 File Systems
Learn more about the different [file systems and their compatibility with different OS here](https://www.youtube.com/watch?v=_h30HBYxtws).
For Linux, the most common one is ext4.

### 🔀 Swap
Swap area is used to keep your applications running when you run out of RAM.
In other words, is a fake RAM that resides in your hard-drive.
Learn more on [Swap area here](https://askubuntu.com/questions/508870/what-is-a-swap-area).

👀 how LVM works and what it is all about??? https://www.ibm.com/docs/en/informix-servers/12.10?topic=storage-logical-volume-manager

<br />

## 3. Finish Installation
* Installing GRUB boot loader? Yes.

### 💡 Package managers: APT vs Aptitude
**Package manager** is a collection of software tools that automates the process of installing, upgrading, configuring and removing computer programmes in a consistent manner (shamelessly copied from Wikipedia).
**APT (Advanced Package Tool)** and **Aptitude** are both package managers for Debian OS.
APT only has a CLI, while Aptitude offers a GUI (and some other additional features).
Learn more about [apt vs aptitude](https://askubuntu.com/questions/347898/whats-difference-of-apt-get-and-aptitude), [these vs dpkg](https://askubuntu.com/questions/309113/what-is-the-difference-between-dpkg-and-aptitude-apt-get), [wajig and apt-get's easter egg](https://unix.stackexchange.com/questions/767/what-is-the-real-difference-between-apt-get-and-aptitude-how-about-wajig).

### 🌫 Mirrors & CDN
In computing, a mirror is a server which is a copy (or mirror) of another.
In this particular case, a mirror is used to reduce the download time, by choosing a mirror closer to your geographical location.
Learn more about [mirrors here](https://techterms.com/definition/mirror).
A [CDN (Content Delivery Network)](https://techterms.com/definition/cdn) is based on the same principle.
It provides data faster from different servers depending on the client's location, and it can also offer different content depending on your location.
It can also lead to a major internet breakage, like the [one a couple of days ago](https://status.fastly.com/incidents/vpk0ssybt3bj) which caused [StackOverflow, some parts of Github and Gitlab, amongst others, to be down](https://www.afterdawn.com/news/article.cfm/2021/06/08/big-chunk-of-internet-is-down-reddit-stackoverflow-and-more).
How [ironic](https://www.facebook.com/AndyDuckersLinks/photos/a.1277293385714886/3922471371197061/?type=3&is_lookaside=1).

### 🚀 GRUB boot loader
[GRUB](https://www.gnu.org/software/grub/) stands for GRand Unified Bootloader.
A boot loader is the first software that runs when a computer starts.
It loads and transfers control over to the kernel, which then takes care of the rest.

<br />

## Extra: Fixing partitions sizes
Your partitions are not quite the way you wanted?
My advice: leave it.
Still want to fix it?
Use ```fdisk```:

```
su                     // to login as root
umount /dev/sdaX       // unmount the partition sdaX
/sbin/fdisk /dev/sda   // in case sbin is not in your PATH
Command: d             // and then choose the partition number to delete
Command: n             // create new, Last sector: +size{unit}
mount /dev/sdaX        // mount it
```

Watch out for empty space: you will obviously need to free space in order to increase a partition's size.

<br />

## 4. AppArmor
* Command not found? [Add sbin to your PATH](https://unix.stackexchange.com/questions/577050/bash-fdisk-command-not-found).

### 🔐 AppArmor vs SELinux
**AppArmor** and **SELinux** (Security-Enhanced Linux) are both independent Linux Security Modules.
They both control who can and cannot access certain files or directories, protecting the OS and other applications from both external and internal threats.
"SELinux controls access based on the labels of the files and processes while AppArmor controls access based on the paths of the program files." (from [this article on AppArmor vs SELinux](https://www.omarine.org/blog/apparmor-vs-selinux/))

<br />

## 5. Sudo
Can't get tired of NetworkChuck's videos - [here's one on sudo](https://www.youtube.com/watch?v=jwnvKOjmtEA).

```
sudo adduser <user_name>             // create a new user, you will be prompted to set up a password
sudo adduser <user_name> <group>     // add user to a group
sudo userdel <user_name>             // delete a user
sudo gpasswd -d <user_name> <group>  // remove a user from a group
sudo groupdel <group>                // delete a group
cat /etc/passwd                      // list of all users
sudo cat /etc/shadow                 // list of all users' passwords (the hashed version, no, not the actual password)
cat /etc/groups                      // list of all groups
sudo passwd <user_name>              // set up/change a user's password
usermod <user_name> -options         // use flag -h to see how you can modify your user
su - <user_name>                     // switch/login as user_name (default/blank is root)
```

Learn how to edit the sudoers file in the [Sudoers Manual](https://www.sudo.ws/man/1.8.17/sudoers.man.html) (scroooolll downnn) and check [some practical examples here](https://www.tecmint.com/sudoers-configurations-for-setting-sudo-in-linux/).

### 📠 TTY
Learn about the [TTY command and its history](https://www.howtogeek.com/428174/what-is-a-tty-on-linux-and-how-to-use-the-tty-command/).
As mentioned in the Sudoers Manual, when this is required the command sudo is only executed when run in a PTY, not via CRON or [CGI-bin scripts](https://www.w3.org/Security/faq/wwwsf4.html) ([Common Gateway Interface](https://www.geeksforgeeks.org/common-gateway-interface-cgi/)).

<br />

## 6. Strong Password
See [how long it takes to brute force your password](https://www.milnsbridge.com.au/wp-content/uploads/2020/09/npq7p60b1lj51-1024x1024.jpg) depending on its length and variety of characters.
```
sudo nano /etc/login.defs
sudo nano /etc/pam.d/common-password
```

👀 advantages of this password policy, as well as advantages and disadvantages of its implementation?

<br />

## 7. VM Network Configuration
* Make sure the network's address is the same in the settings and in the /etc/network/interfaces file
* DHCP enabled: the VM's IP address is attributed by the DHCP server
* In this case: we defined the VM's IP address in the /etc/network/interfaces file (and set it as static) and disabled DHCP
* Find out more on [how to configurate /etc/network/interfaces file here](https://linuxhint.com/debian_etc_network_interfaces/)

### 🕸 NAT & Host-only networks
[**NAT** (Network Address Translator)](https://www.youtube.com/watch?v=01ajHxPLxAw) allows us to associate multiple machines to a single IP address, by using some bits from the TCP header in the data package to extend the IP address space.
More specifically, NAT uses the bits associated with the Port number.

NAT allows the [VM to use the host's computer network resources](https://www.vmware.com/support/ws3/doc/ws32_network21.html).
Any TCP/IP connection the host machine has access to should be available to the VM via NAT.
This is why you were immediately able to connect to the internet through your VM.
Note that as far as the VM is concerned, the VM is accessing the external network directly, meaning it is not aware of the host and its intermediary position.

**Host-only networks** are networks between the host computer and the VM, established via a [virtual ethernet adapter](https://www.techopedia.com/definition/15630/virtual-network-adapter).
Unlike in the previous case, here the VM is fully aware of the host, and communicating with it.
This is necessary for being able to access the VM from your host via SSH.

<br />

## 8. SSH
Watch [Computerphile's video on SSH (Secure Shell)](https://www.youtube.com/watch?v=ORcvSkgdA58).

<br />

## 9. UFW - Uncomplicated Firewall
👀 Read about firewalls and ufw
Nat and firewall (?): https://www.youtube.com/watch?v=2llWuivdS7w
iptables???
Learn more [ufw commands here](https://www.tecmint.com/how-to-install-and-configure-ufw-firewall/).

<br />

## 10. Monitoring script
```
MEM_TOTAL=$(free | awk '/Mem/ {printf("%0.f\n", $2 / 1024)}')
MEM_USED=$(free | awk '/Mem/ {printf("%0.f\n", $3 / 1024)}')
MEM_USED_PERCENT=$(echo "$MEM_USED $MEM_TOTAL" | awk '{printf ("%.2f", ($1 / $2) * 100)}')

DISK_USED=$(df --output=used | tail --lines=+2 | paste -sd+ | bc | awk '{printf("%.0f\n", $1 / 1024)}')
DISK_AVAIL_MB=$(df --output=avail | tail --lines=+2 | paste -sd+ | bc | awk '{printf("%.0f\n", $1 / 1024)}')
DISK_AVAIL_GB=$(echo "$DISK_AVAIL_MB" | awk '{printf ("%d", ($1 / 1024))}')
DISK_AVAIL_PERCENT=$(echo "$DISK_USED $DISK_AVAIL_MB" | awk '{printf ("%.2f", ($1 / $2) * 100)}')

LAST_BOOT=$(uptime -s)
LAST_BOOT=${LAST_BOOT::-3}

LVM_COUNT=$(lsblk -o TYPE | grep lvm | wc -l)
HAS_LVM="no"
if [[ "$LVM_COUNT" > 0 ]]
then
        HAS_LVM="yes"
fi

echo "Broadcast message from" $(whoami)"@"$(hostnamectl | awk '/Static hostname/ {print $3}') "("$(tty | awk -F/ '{print $3}')")" $(date)
echo "#Architecture: " $(uname -a)
echo "#CPU physical :" $(cat /proc/cpuinfo | grep 'physical id' | sort -u | wc -l)
echo "#vCPU :" $(nproc)
echo "#Memory Usage:" "${MEM_USED}/${MEM_TOTAL}MB" "($MEM_USED_PERCENT%)"
echo "#Disk Usage:" "${DISK_USED}MB/${DISK_AVAIL_GB}GB" "($DISK_AVAIL_PERCENT%)"
echo "#CPU load:" $(grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {printf("%.2f%%\n", usage)}')
echo "#Last boot: $LAST_BOOT"
echo "#LVM: $HAS_LVM"
echo "Connections TCP:" $(grep '^ *[0-9]\+: [0-9A-F: ]\{27\} 01 ' /proc/net/tcp -c) "ESTABLISHED"
echo "#User log:" $(who | awk '{print $1}' | sort -u | wc -l)
echo "#Network: IP" $(hostname -I | awk '{print $2}') "("$(ip a | grep ether | tail -n 1 | awk '{print $2}')")"
echo "#Sudo : $(cat /var/log/sudo/sudo.log | grep -c COMMAND) cmd"
```
* Different VMs might be using the same physical processor, so the same ID might be listed more than once, thus sort -u to filter unique keys;
* How to use [awk command](https://www.howtogeek.com/562941/how-to-use-the-awk-command-on-linux/);
* Note: you will have to install bc;
* [CPU usage](https://supportcenter.checkpoint.com/supportcenter/portal?eventSubmit_doGoviewsolutiondetails=&solutionid=sk65143) = (user + system) / (user + system + [idle](https://dictionary.cambridge.org/dictionary/english/idle);
* Active TCP connections: [st 01](https://stackoverflow.com/questions/5992211/list-of-possible-internal-socket-statuses-from-proc);
* Add CRON job as a job from root, so that you have the necessary permissions to check sudo.log

👀 Check:
MemFree vs MemAvailable
What is CRON? related to jobs
https://www.hostinger.com/tutorials/cron-job

<br />

## 🙋‍♀️ Defence
Some additional useful commands for the defense:
```
sudo ufw status
telnet localhost 4242                     // check ssh status
uname -a                                  // check OS
hostnamectl                               // check hostname
sudo hostnamectl set-hostname <new-host>  // update hostname
sudo ufw allow 8080/tcp                   // openning port 8080
sudo ufw deny 8080/tcp                    // close the port 8080
crontab -r                                // remove current crontab file
// make monitoring script stop running at start up?
```

All the files I modified:
Sudo:
/etc/sudoers

Password:
/etc/login.defs
/etc/pam.d/common-password

SSH:
/etc/ssh/sshd_config

<br />

*This ReadMe is under construction!*

42 student repo: https://github.com/hanshazairi/42-born2beroot

Happy virtualisation! 👻
