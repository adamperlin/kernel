#ifndef SYSTEM_H
#define SYSTEM_H

#define NULL 0


unsigned char *memcpy(void *dest, const void *src, int count);
unsigned char *memset(void *dest, char val, int count);
unsigned short *memsetw(unsigned short *dest, unsigned short val, int count);
int strlen(const char *str);
unsigned char inportb(unsigned short);
void outportb(unsigned short, unsigned char);

struct regs {
  unsigned int gs, fs, es, ds; //segment registers; are pushed last.
  unsigned int edi, esi, ebp, esp, ebx, edx, ecx, eax; /* pushed by pusha instruction */
  unsigned int int_no, err_code; /*set by push byte error codes in boot.S*/
  unsigned int eip, cs, eflags, useresp, ss; /*pushed by cpu automatically*/
};

void isrs_install();


#endif
