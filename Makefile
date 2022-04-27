obj-m := hrtimer_mod.o
CFLAGS_hrtimer_mod.o := -std=gnu99

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean