make

echo "Loading kernel module ..."
sudo insmod hrtimer_mod.ko
sudo dmesg | tail -1

count=1
while [ $count -le 10 ]
do
	sleep 1
    sudo dmesg | tail -1
    count=$(( $count + 1 ))
done

echo "Removing kernel module ..."
sudo rmmod hrtimer_mod
sudo dmesg | tail -1

make clean
