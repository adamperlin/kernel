#ifndef GDT_H
#define GDT_H

extern void gdt_set_gate(int, unsigned long, unsigned long, unsigned char, unsigned char);
extern void gdt_install();

#endif
