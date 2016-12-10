#include <system.h>
#include <tty.h>
#include <gdt.h>
#include <idt.h>
#include <irq.h>
#include <timer.h>
#include <keyboard.h>
#include <string.h>

extern void idt_install();
void init();

void main() {
  init();
  __asm__ __volatile__("sti");
  //int var = 10 / 0;
  puts("hello kernel world!\n");
  puts("this is another line!\n");

  /*if (sizeof(struct idt_entry) == 8) {
    puts("correct size.");
  } else {
    puts("incorrect size.\n");
  }

  char buff[20];
  itoa(sizeof(struct idt_entry), buff, 10);

  puts("struct idt entry size: ");
  puts(buff);
  */

  puts("type here: ");


for(;;);
}

void init() {
  gdt_install();
  idt_install();
  isrs_install();
  irq_install();
  timer_install();
  keyboard_install();
  init_video();
}
