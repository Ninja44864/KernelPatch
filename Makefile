# This MUST match the name of your file in the src folder
# If your file is src/hello.c, keep it as src/hello.o
obj-m += src/hello.o

# The KDIR is provided by the environment in the GitHub runner
all:
	@echo "Compiling KPM for Android..."
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean
