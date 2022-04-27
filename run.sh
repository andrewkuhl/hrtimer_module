make

echo "Loading kernel module ..."
sudo insmod hrtimer_mod.ko

sleep 10

echo "Removing kernel module ..."
sudo rmmod hrtimer_mod

echo "dmesg output"
sudo dmesg | tail -12

make clean
