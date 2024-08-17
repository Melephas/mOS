### Configuration ###
TARGET = i686-elf
ARCH = i386
ARCH_DEFINE = _MOS_K_ARCH_I386

# Directories
OBJECT_DIR = obj
TOOLCHAIN_DIR = ../toolchain/bin
ARCH_DIR = arch/$(ARCH)
OBJECT_ARCH_DIR = $(OBJECT_DIR)/$(ARCH_DIR)

### Files ###
LINK_SCRIPT = $(ARCH_DIR)/linker.ld
KERNEL = mOS.bin
OBJECTS = 	$(OBJECT_DIR)/kernel.o \
			$(OBJECT_DIR)/arch/$(ARCH)/boot.o \
			$(OBJECT_DIR)/arch/$(ARCH)/crti.o \
			$(OBJECT_DIR)/arch/$(ARCH)/crtn.o \
			$(OBJECT_DIR)/arch/$(ARCH)/i386_utils.o \
			$(OBJECT_DIR)/arch/$(ARCH)/vga.o

### Programs ###
AS = $(TOOLCHAIN_DIR)/$(TARGET)-as
AS_FLAGS = -g

LD = $(TOOLCHAIN_DIR)/$(TARGET)-ld
LD_FLAGS = -T $(LINK_SCRIPT)

CC = $(TOOLCHAIN_DIR)/$(TARGET)-gcc
CC_FLAGS = -ffreestanding -O2 -I ./ -D $(ARCH_DEFINE) -g
CC_COMPILE_FLAGS = $(CC_FLAGS) -std=gnu99 -Wall -Wextra
CC_LINK_FLAGS = $(CC_FLAGS) $(LD_FLAGS) -nostdlib -lgcc

### Link phase ###
$(KERNEL): $(OBJECTS) $(OBJECT_DIR)
	$(CC) $(CC_LINK_FLAGS) -o $@ $(OBJECTS)

### Compile phase ###
$(OBJECT_DIR)/%.o: %.c $(OBJECT_DIR)
	$(CC) $(CC_COMPILE_FLAGS) -c $< -o $@

$(OBJECT_DIR)/%.o: %.s $(OBJECT_ARCH_DIR)
	$(AS) $(AS_FLAGS) $< -o $@

### Misc phase ###
$(OBJECT_DIR) $(OBJECT_ARCH_DIR):
	mkdir -p $@

### Extra stuff ###
.PHONY: all clean

all: $(KERNEL)

clean:
	$(RM) -r $(OBJECT_DIR) $(KERNEL) kernel.sym

kernel.sym: $(KERNEL)
	$(TOOLCHAIN_DIR)/$(TARGET)-objcopy --only-keep-debug $< $@
