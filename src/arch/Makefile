ASM=nasm
ASMFLAGS=-f elf32
ASMFILES=boot.S
ASMOBJS=$(ASMFILES:.S=.o)
LINKER=ld
LDFLAGS=-m elf_i386 -T
INCLUDE=../include
CC=i386-elf-gcc
CPP=i386-elf-g++
CFLAGS=-Wall -O -fstrength-reduce -fomit-frame-pointer -finline-functions -ffreestanding -nostdinc -std=c11 -I$(INCLUDE) -c
CPPFLAGS=-Wall -Wwrite-strings -O -fstrength-reduce -fomit-frame-pointer -finline-functions -ffreestanding -nostdinc -std=c++11 -I$(INCLUDE) -c 
ARCHFILES=tty.c system.c gdt.c idt.c isr.c string.c irq.c timer.c keyboard.c
ARCHFILESCPP=main.cpp
CPPOBJS=$(ARCHFILESCPP:.cpp=.o)
OBJECTS=$(ARCHFILES:.c=.o)
LINKERSCRIPT=linker.ld
EXE=kernel.bin

all: $(EXE)

$(EXE):  $(CPPOBJS) $(OBJECTS) $(ASMOBJS)
	$(LINKER) $(LDFLAGS) $(LINKERSCRIPT) -o $(EXE) $(CPPOBJS) $(OBJECTS) $(ASMOBJS)

.cpp.o:
	$(CPP) $(CPPFLAGS) $< -o $@
.c.o:
	$(CC) $(CFLAGS) $< -o $@

.S.o:
	$(ASM) $(ASMFLAGS) $< -o $@

clean:
	rm *o kernel.bin
