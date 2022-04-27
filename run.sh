make

echo "Loading kernel module ..."
sudo insmod hrtimer_mod.ko

count=1
while [ $count -le 10 ]
do
	sleep 1
    echo "$count second(s)"	
    count=$(( $count + 1 ))
done

echo "Removing kernel module ..."
sudo rmmod hrtimer_mod

echo "dmesg output"
sudo dmesg | tail -12

make clean
