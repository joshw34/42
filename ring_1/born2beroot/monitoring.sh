#!/bin/bash

ARCH=$(uname -vo)
CPU_PHYSICAL=$(lscpu | awk '/^Socket\(s\):/{sockets=$2} /^Core\(s\) per socket:/{cores=$4} END{print sockets*cores}')
CPU_VIRTUAL=$(lscpu | awk '/^CPU\(s\):/{print $2}')
RAM_USED=$(free -m | awk '/^Mem:/{print $3}')
RAM_TOTAL=$(free -m | awk '/^Mem:/{print $2}')
RAM_PERCENT=$(free -m | awk '/^Mem:/{used=$3} /^Mem:/{total=$2} END{printf "%.1f", used/total*100}')
DISK_USED=$(df -h --total | awk '/^total/{print $3}')
DISK_TOTAL=$(df -h --total | awk '/^total/{print $2}')
DISK_PERCENT=$(df -h --total | awk '/^total/{print $5}')
CPU_USAGE=$(top -bn1 | awk '/Cpu\(s\)/{print $2 + $4}')
REBOOT=$(uptime -s)
LVM=$(if [ $(lsblk | grep lvm | wc -l) -lt 1 ]; then echo no; else echo yes; fi)
TCP=$(netstat -ant | grep ESTABLISHED | wc -l)
USERS=$(who | wc -l)
IP_ADDRESS=$(hostname -i)
MAC=$(ip address | awk '/link\/ether/{print $2}')
SUDO=$(cat /var/log/sudo/sudo.log | grep COMMAND | wc -l)

wall "Architecture: $ARCH
Physical CPUs: $CPU_PHYSICAL
Virtual CPUs: $CPU_VIRTUAL
Memory Usage: $RAM_USED/$RAM_TOTAL MB ($RAM_PERCENT%)
Disk Usage: $DISK_USED/$DISK_TOTAL ($DISK_PERCENT)
CPU Usage: $CPU_USAGE%
Last Reboot: $REBOOT
LVM Active: $LVM
TCP Connections: $TCP ESTABLISHED
Users: $USERS
Network: IP Address $IP_ADDRESS MAC $MAC
Sudo: $SUDO commands
"
