NAME = I2Ctest
KDIR := /usr/src/linux-headers-6.4.1

obj-m := $(NAME).o
$(NAME)-objs := main.o oled.o
PWD := $(shell pwd)

all:
	make -C $(KDIR) M=$(PWD) modules

clean:
	-rm -rf *.o *.ko *.order $(NAME).mod.c Module.symvers .*.o.cmd .$(NAME).ko.cmd $(NAME).mod .$(NAME).mod.cmd

load:
	insmod $(NAME).ko

unload:
	rmmod $(NAME)

.PHONY: all clean load unload