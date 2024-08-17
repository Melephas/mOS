PREFIX = $(shell pwd)
TARGET = i686-elf

BINUTILS_URL = https://ftp.gnu.org/gnu/binutils/binutils-2.43.tar.xz
GCC_URL = https://ftp.gnu.org/gnu/gcc/gcc-14.2.0/gcc-14.2.0.tar.xz

WGET_FLAGS = -q --show-progress

MAKE_FLAGS = -j $(shell nproc --all)

.PHONY: all
all: binutils gcc

binutils.tar.xz:
	wget $(WGET_FLAGS) $(BINUTILS_URL) -O $@

binutils_src: binutils.tar.xz
	mkdir -p $@
	tar -xaf $< -C $@ --strip-components 1

binutils: binutils_src
	mkdir -p $@
	cd $@; ../$</configure --target=$(TARGET) --prefix="$(PREFIX)" --with-sysroot --disable-nls --disable-werror
	$(MAKE) $(MAKE_FLAGS) -C $@
	$(MAKE) $(MAKE_FLAGS) -C $@ install

gcc.tar.xz:
	wget $(WGET_FLAGS) $(GCC_URL) -O $@

gcc_src: gcc.tar.xz
	mkdir -p $@
	tar -xaf $< -C $@ --strip-components 1

gcc: gcc_src
	mkdir -p $@
	cd $@; ../$</configure --target=$(TARGET) --prefix="$(PREFIX)" --disable-nls --enable-languages=c,c++ --without-headers
	$(MAKE) $(MAKE_FLAGS) -C $@ all-gcc
	$(MAKE) $(MAKE_FLAGS) -C $@ all-target-libgcc
	$(MAKE) $(MAKE_FLAGS) -C $@ install-gcc
	$(MAKE) $(MAKE_FLAGS) -C $@ install-target-libgcc


.PHONY: clean-gcc clean-binutils clean clean-tars clean-products clean-all

clean-gcc:
	$(RM) -r gcc

clean-binutils:
	$(RM) -r binutils

clean: clean-gcc clean-binutils
	$(RM) -r *_src

clean-tars:
	$(RM) *.tar*

clean-products:
	$(RM) -r bin i686-elf lib share include libexec

clean-all: clean clean-tars clean-products