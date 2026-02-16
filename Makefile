# Ensure this matches your filename in the src folder
obj-m += src/kpm.o

# This is the standard path where the NDK/APatch looks for the build system
KDIR ?= /lib/modules/$(shell uname -r)/build

all:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
