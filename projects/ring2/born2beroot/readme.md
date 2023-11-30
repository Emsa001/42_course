## Part 4 - Configurating Your Virtual Machine

### Part 4.1 - Installing Sudo

1. First type `su -` to login in as the root user.
2. Then type `apt-get update -y` 
3. Then type `apt-get upgrade -y` 
4. Then type `apt install sudo`
5. Then type `usermod -aG sudo your_username` to add user in the sudo group (To check if user is in sudo group, type `getent group sudo`)
6. Type `sudo visudo` to open sudoers file
7. Lastly find - # User privilege specification, type `your_username  	ALL=(ALL) ALL`

### Part 4.2 - Installing Git and Vim

1. Then type `apt-get install git -y` to install Git
2. Then type `git --version` to check the Git Version

### Part 4.3 - Installing and Configuring SSH (Secure Shell Host)

1. Type `sudo apt install openssh-server`
2. Type `sudo systemctl status ssh` to check SSH Server Status
3. Type `sudo vim /etc/ssh/sshd_config`
4. Find this line `#Port22` 
5. Change the line to `Port 4242` without the # (Hash) in front of it
6. Save and Exit Vim 
7. Then type `sudo grep Port /etc/ssh/sshd_config` to check if the port settings are right
8. Lastly type `sudo service ssh restart` to restart the SSH Service 

### Part 4.4 - Installing and Configuring UFW (Uncomplicated Firewall)

1. First type `apt-get install ufw` to install UFW
2. Type `sudo ufw enable` to inable UFW
3. Type `sudo ufw status numbered` to check the status of UFW
4. Type `sudo ufw allow ssh` to configure the Rules
5. Type `sudo ufw allow 4242` to configure the Port Rules
6. Lastly Type `sudo ufw status numbered` to check the status of UFW 4242 Port


## Part 5 Connecting to SSH

0. To exit your Virtual Machine and use your mouse, press `command` on your Apple Keyboard and your mouse should appear
1. Go to your Virtual Box Program
2. Click on your Virtual Machine and select `Settings`
3. Click `Network` then `Adapter 1` then `Advanced` and then click on `Port Forwarding`
![1*rCj_FeuZ5Rm2abz48qhulg](https://user-images.githubusercontent.com/58959408/174720900-39eda7e0-9be8-453c-94f1-4aa1a6b10951.png)
4. Change the Host Port and Guest Port to `4242`
![1*61-KSUCFcerO1wPqBcYISg](https://user-images.githubusercontent.com/58959408/174720987-e8de3bf9-2ffa-40ca-9d5c-4d0dea9d0b30.png)
5. Then head back to your Virtual Machine
6. Type `sudo systemctl restart ssh` to restart your SSH Server
7. Type `sudo service sshd status` to check your SSH Status
8. Open an iTerm and type the following `ssh your_username@127.0.0.1 -p 4242`
9. In case an error occurs, then type `rm ~/.ssh/known_hosts` in your iTerm and then retype `ssh your_username@127.0.0.1 -p 4242`
10. Lastly type `exit` to quit your SSH iTerm Connection 


## Part 6 - Continue Configurating Your Virtual Machine

### Part 6.1 - Setting Password Policy

1. First type `sudo apt-get install libpam-pwquality` to install Password Quality Checking Library
2. Then type `sudo vim /etc/pam.d/common-password`

3. Find this line. `password		requisite		pam_deny.so` or
<img width="828" alt="Screen Shot 2022-07-29 at 6 40 34 PM" src="https://user-images.githubusercontent.com/58959408/181726262-8f8b7027-1929-4dda-8ac5-3957d3a1bd3a.png">
4. Add this to the end of that line `minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`

- 4.1 The line should now look like this - `password  requisite     pam_pwquality.so  retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`
<img width="800" alt="179329787-1b718843-9272-43e4-8d92-8d83933cc938" src="https://user-images.githubusercontent.com/58959408/181725921-c1e6c2b1-9dd3-46c5-b738-111467bdb394.png">

5. Save and Exit Vim
6. Next type in your Virtual Machine `sudo vim /etc/.in.defs`
7. Find this part `PASS_MAX_DAYS 9999` `PASS_MIN_DAYS 0` `PASS_WARN_AGE 7`
8. Change that part to `PASS_MAX_DAYS 30` and `PASS_MIN_DAYS 2` keep `PASS_WARN_AGE 7` as the same
9. Lastly type `sudo reboot` to reboot the change affects
10. sudo chage -M <new_max_days> -m <new_min_days> -W <new_warn_age> <username> (I don't know if necessary, I think it should only be for new users)

### Part 6.2 - Creating a Group

1. First type `sudo groupadd user42` to create a group
2. Then type `sudo groupadd evaluating` to create an evaluating group
3. Lastly type `getent group` to check if the group has been created

### Part 6.3 - Creating a User and Assigning Them Into The Group

1. First type `cut -d: -f1 /etc/passwd` to check all local users
2. Type `sudo adduser new_username` to create a username - write down your new_username, as you will need this later on. 
- 2.1 Type `sudo usermod -aG user42 your_username`
- 2.2 Type `sudo usermod -aG evaluating your_new_username`
3. Type `getent group user42` to check if the user is the group
4. Type `getent group evaluating` to check the group
5. Type `groups` to see which groups the user account belongs to
6. Lastly type `chage -l your_new_username` to check if the password rules are working in users

### Part 6.4 - Creating sudo.log

1. First type `cd ~/../`
4. Then type `cd var/log/`
5. Then type `mkdir sudo` (if it already exists, then continue to the next step).
6. Then type `cd sudo && touch sudo.log`
7. Then type `cd ~/../`

### Part 6.4.1 - Configuring Sudoers Group

1. First type `sudo nano /etc/sudoers` to go the sudoers file
2. Now edit your sudoers file to look like the following by adding in all of the defaults in the image below - ![1*N4Ad-9k0vfvnWKNC5q6MjQ](https://user-images.githubusercontent.com/58959408/174725518-0ebf1dac-4126-4869-9ba0-b1d05ce313c9.png)

```
Defaults	env_reset
Defaults	mail_badpass
Defaults	secure_path="/usr/local/sbin:/usr/local/bin:/usr/bin:/sbin:/bin"
Defaults	badpass_message="Password is wrong, please try again!"
Defaults	passwd_tries=3
Defaults	logfile="/var/log/sudo.log"
Defaults	log_input, log_output
Defaults	requiretty
```

### Part 6.5 - Crontab Configuation

1. Then type `apt-get install -y net-tools` to install the netstat tools
2. Then type `cd /usr/local/bin/`
3. Then type `touch monitoring.sh`
4. Lastly type `chmod 777 monitoring.sh`

### Part 6.5.1 - Copy Text Below onto Virtual Machine 

1. Copy this text (To copy the text below, hover with your mouse to the right corner of the text below and a copy icon will appear). 
```
#!/bin/bash
arc=$(uname -a)
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l) 
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l)
fram=$(free -m | awk '$1 == "Mem:" {print $2}')
uram=$(free -m | awk '$1 == "Mem:" {print $3}')
pram=$(free | awk '$1 == "Mem:" {printf("%.2f"), $3/$2*100}')
fdisk=$(df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{ft += $2} END {print ft}')
udisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} END {print ut}')
pdisk=$(df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{ut += $3} {ft+= $2} END {printf("%d"), ut/ft*100}')
cpul=$(top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}')
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')
lvmu=$(if [ $(lsblk | grep "lvm" | wc -l) -eq 0 ]; then echo no; else echo yes; fi)
ctcp=$(ss -neopt state established | wc -l)
ulog=$(users | wc -w)
ip=$(hostname -I)
mac=$(ip link show | grep "ether" | awk '{print $2}')
cmds=$(journalctl _COMM=sudo | grep COMMAND | wc -l)
wall "	#Architecture: $arc
	#CPU physical: $pcpu
	#vCPU: $vcpu
	#Memory Usage: $uram/${fram}MB ($pram%)
	#Disk Usage: $udisk/${fdisk}Gb ($pdisk%)
	#CPU load: $cpul
	#Last boot: $lb
	#LVM use: $lvmu
	#Connections TCP: $ctcp ESTABLISHED
	#User log: $ulog
	#Network: IP $ip ($mac)
	#Sudo: $cmds cmd"
```
2. Then open up a iTerm2 seperate from your Virtual Machine and type in iTerm `ssh your_host_name42@127.0.0.1 -p 4242` and then type your password, when it asks for it. 
3. Then type `cd /usr/local/bin`.
4. Then type `nano monitoring.sh` and paste the text above into the vim monitoring.sh you just created, by doing `command` + `v` on your Apple keyboard.
5. Save and Exit your `monitoring.sh`
- 5.1 - Then type `exit` to exit the iTerm SSH Login.
- 5.2 - Then go back to your Virtual Machine (not iTerm) and continue on with the steps below. 
6. Then type `sudo visudo` to open your sudoers file 
7. Add in this line `your_username ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh` under where its written %sudo ALL=(ALL:ALL) ALL
8. It should look like this
![1*l-7LtAqCon1gRkV3dY3qiQ](https://user-images.githubusercontent.com/58959408/174727595-11dbb2f9-9c34-4d11-870b-f832ea4a9224.png)
9. Then exit and save your sudoers file
10. Now type `sudo reboot` in your Virtual Machine to reboot sudo
11. Type `sudo /usr/local/bin/monitoring.sh` to execute your script as su (super user)
12. Type `sudo crontab -u root -e` to open the crontab and add the rule
13. Lastly at the end of the crontab, type the following `*/10 * * * * /usr/local/bin/monitoring.sh` this means that every 10 mins, this script will show


## Part 7 - Signature.txt (Last Part Before Defence)

⚠️ Warning: before you generate a signature number, turn off your Virtual Machine. ⚠️

1. Open iTerm and type `cd`
1. Then type `cd sgoinfre/students/<your_intra_username>/VirtualBox VMs`
2. Type `shasum VirtualBox.vdi` or whatever your Virtual Machine is called (This can take from a few seconds to 5 mins).
3. Copy the output number and create a signature.txt file and paste that number in the file. 
3. Now you submit the signature.txt file with the output number in it. 

### 🥳 CONGRATULATIONS! YOU HAVE NOW FINISHED! NEXT IS THE EVALUATION 🔽
<br>

## Part 8 - Born2BeRoot Defence Evaluation with Answers

[Link](https://docs.google.com/document/d/1-BwCO0udUP7MhRh81Y681zz0BalXtKFtte_FHJc6G4s/edit) to the [Born2BeRoot Evaluation Checklist](https://docs.google.com/document/d/1-BwCO0udUP7MhRh81Y681zz0BalXtKFtte_FHJc6G4s/edit) created by [Adrian Musso-Gonzalez](https://github.com/AdrianMussoGonzalez).

### The Evaluation Questions

### Why did I choose Debian?
Easier to install and configure so better for personal servers.

### Difference between Debian and CentOS?
Debian is a lot easier to update then CentOS when a new version is released. Debian is more user-friendly and supports many libraries, filesystems and architecture. It also has more options for customisation. If you are a larger business CentOS offers more Enterprise features and excellent support for the Enterprise software. 

![1*EUhkzOMoiT_KEF3j402O6g](https://user-images.githubusercontent.com/58959408/175495740-d4599f59-25b1-43ba-9c01-ba4246096f8a.png)

### What is a Virtual Machine?
Is a resource that uses software instead of a physical computer to run programs or apps. Each VM has its own operating system and functions separately, so you can have more than one VM per machine. Can be used to test applications in a safe, separate environment. Works by using software to simulate virtual hardware and run on a host machine.

### What is the difference between aptitude and APT (Advanced Packaging Tool)?
* Aptitude is a high-level package manager while APT is lower level which can be used by other higher level package managers
* Aptitude is smarter and will automatically remove unused packages or suggest installation of dependent packages
* Apt will only do explicitly what it is told to do in the command line

### What is AppArmor?
Linux security system that provides Mandatory Access Control (MAC) security. Allows the system admin to restrict the actions that processes can perform. It is included by default with Debian. Run aa-status to check if it is running.

### Password Rules
For the password rules, we use the password quality checking library and there are two files the common-password file which sets the rules like upper and lower case characters, duplicate characters etc and the login.defs file which stores the password expiration rules (30 days etc).
Sudo nano /etc/login.defs
Sudo nano /etc/pam.d/common-password

### What is LVM
Logical Volume Manager – allows us to easily manipulate the partitions or logical volume on a storage device. 

### UFW (Uncomplicated Firewall) 
UFW is a interface to modify the firewall of the device without compromising security. You use it to configure which ports to allow connections to and which ports to close. This is useful in conjunction with SSH, can set a specific port for it to work with.

### What is SSH?
SSH or Secure Shell is an authentication mechanism between a client and a host. It uses encryption techniques so that all communication between clients and hosts is done in encrypted form. User on Mac or Linux can use SSH the terminal to work on their server via SSH.

### What is Cron?
Cron or cron job is a command line utility to schedule commands or scripts to happen at specific intervals or a specific time each day. Useful if you want to set your server to restart at a specific time each day. 

- `cd /usr/local/bin` – to show monitoring.sh
- `sudo crontab -u root -e` – to edit the cron job
- `change script to */1 * * * * sleep 30s && script path` – to run it every 30 seconds, delete the line to stop the job from running.

### Evaluation Commands for UFW, Group, Host, lsblk and SSH

- `sudo ufw status`
- `sudo systemctl status ssh`
- `getent group sudo`
- `getent group user42`
- `sudo adduser new username`
- `sudo groupadd groupname`
- `sudo usermod -aG groupname username`
- `sudo chage -l username` - check password expire rules
- `hostnamectl`
- `hostnamectl set-hostname new_hostname` - to change the current hostname
- Restart your Virtual Machine.
- `sudo nano /etc/hosts` - change current hostname to new hostname
- `lsblk` to display the partitions
- `dpkg -l | grep sudo –` to show that sudo is installed
- `sudo ufw status numbered`
- `sudo ufw allow port-id`
- `sudo ufw delete rule number`
- `ssh your_user_id@127.0.0.1 -p 4242` -  do this in terminal to show that SSH to port 4242 is working