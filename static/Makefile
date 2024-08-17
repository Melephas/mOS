ISO_DIR = iso
BOOT_DIR = $(ISO_DIR)/boot
GRUB_DIR = $(BOOT_DIR)/grub

GRUB_CFG = $(GRUB_DIR)/grub.cfg
KERNEL = $(BOOT_DIR)/mOS.bin

ISO_FILE = mOS.iso
KERNEL_BIN = mOS.bin

.PHONY: all clean $(KERNEL_BIN)
all: $(ISO_FILE)

clean:
	$(RM) -r $(ISO_DIR) $(ISO_FILE) $(KERNEL_BIN)

$(ISO_FILE): $(GRUB_CFG) $(GRUB_DIR) $(KERNEL)
	grub-mkrescue -o $@ $(ISO_DIR)

$(KERNEL): $(KERNEL_BIN) $(BOOT_DIR)
	cp $(KERNEL_BIN) $(BOOT_DIR)

$(GRUB_CFG): grub.cfg $(GRUB_DIR)
	cp grub.cfg $(GRUB_DIR)

$(GRUB_DIR): $(BOOT_DIR)
	mkdir -p $@

$(BOOT_DIR): $(ISO_DIR)
	mkdir -p $@

$(ISO_DIR):
	mkdir -p $@
