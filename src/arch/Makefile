ASM=nasm
ASMFLAGS=-f elf32
ASMFILES=boot.S
ASMOBJS=$(ASMFILES:.S=.o)
LINKER=ld
LDFLAGS=-m elf_i386 -T
INCLUDE=../include
CC=i386-elf-gcc
CFLAGS=-Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -ffreestanding -nostdinc -std=c11 -I$(INCLUDE) -c
ARCHFILES=tty.c main.c system.c gdt.c idt.c isr.c string.c irq.c timer.c keyboard.c
OBJECTS=$(ARCHFILES:.c=.o)
LINKERSCRIPT=linker.ld
EXE=kernel.bin

all: $(EXE)

$(EXE): $(OBJECTS) $(ASMOBJS)
	$(LINKER) $(LDFLAGS) $(LINKERSCRIPT) -o $(EXE) $(OBJECTS) $(ASMOBJS)


.c.o:
	$(CC) $(CFLAGS) $< -o $@

.S.o:
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm *o kernel.bin
