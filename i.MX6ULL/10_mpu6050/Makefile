CROSS_COMPILE 	?= arm-linux-gnueabihf-
TARGET		  	?= mpu6050

CC 				:= $(CROSS_COMPILE)gcc
LD				:= $(CROSS_COMPILE)ld
OBJCOPY 		:= $(CROSS_COMPILE)objcopy
OBJDUMP 		:= $(CROSS_COMPILE)objdump

#LIBPATH			:= -lgcc -L /etc/arm/gcc/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/lib/gcc/arm-linux-gnueabihf/4.9.4
LIBPATH			:= -lgcc -L  /etc/arm/gcc/lib/gcc/arm-linux-gnueabihf/7.5.0/

INCDIRS 		:= imx6ull \
				   include 
				   			   
SRCDIRS			:= project \
				   src 
				   
				   
INCLUDE			:= $(patsubst %, -I %, $(INCDIRS))

SFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.S))
CFILES			:= $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.c))

SFILENDIR		:= $(notdir  $(SFILES))
CFILENDIR		:= $(notdir  $(CFILES))

SOBJS			:= $(patsubst %, obj/%, $(SFILENDIR:.S=.o))
COBJS			:= $(patsubst %, obj/%, $(CFILENDIR:.c=.o))
OBJS			:= $(SOBJS) $(COBJS)

VPATH			:= $(SRCDIRS)
TOOLS_DIR := ./tools

.PHONY: clean
	
$(TARGET).bin : $(OBJS)
	$(LD) -T$(TOOLS_DIR)/imx6ull.lds -o $(TARGET).elf $^ $(LIBPATH)
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis
	$(TOOLS_DIR)/mkimage -n $(TOOLS_DIR)/imximage.cfg.cfgtmp -T imximage -e 0x87800000 -d $(TARGET).bin $(TARGET).imx
	dd if=/dev/zero of=$(TOOLS_DIR)/1k.bin bs=1024 count=1
	cat $(TOOLS_DIR)/1k.bin $(TARGET).imx > $(TARGET).img

$(SOBJS) : obj/%.o : %.S
	$(CC) -Wall -nostdlib -fno-builtin -c -O2  $(INCLUDE) -o $@ $<

$(COBJS) : obj/%.o : %.c
	$(CC) -Wall -Wa,-mimplicit-it=thumb -nostdlib -fno-builtin -c -O2  $(INCLUDE) -o $@ $<

run:
	sudo uuu ./$(TARGET).imx /dev/hidraw1

download:
	make clean
	make -j4
	make run
clean:
	rm -rf $(TARGET).elf $(TARGET).dis $(TARGET).bin $(TARGET).img $(TARGET).imx $(COBJS) $(SOBJS)


	
