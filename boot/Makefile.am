include $(top_srcdir)/common.mk

noinst_PROGRAMS = corbenik
corbenik_CFLAGS=$(AM_CFLAGS) -T$(srcdir)/linker.ld -nostartfiles
corbenik_LDFLAGS=$(AM_LDFLAGS) -lctr9 -Wl,-Map,corbenik.map
EXTRA_DIST = linker.ld

install:

all-local: corbenik.bin

clean-local:
	rm -f corbenik.bin

corbenik.bin: corbenik
	$(OBJCOPY) $(OCFLAGS) -O binary corbenik corbenik.bin

corbenikdir = $(top_srcdir)/source

inc_dir = $(top_srcdir)/include

corbenik_SOURCES = \
	start.s corbenik.c \
	menu.c menu-backend.c interrupt.c arm11.c interpreter.c input.c patcher.c chainloader.c \
	patch/reboot.c patch/svc.c patch/module.c patch/emunand.c \
	std/fs.c std/draw.c std/memory.c std/abort.c \
	firm/util.c firm/keys.c firm/firmlaunch.c firm/version.c firm/firm.c firm/decryptor.c \
	configback/file-dat.c ../common/lzss.c
