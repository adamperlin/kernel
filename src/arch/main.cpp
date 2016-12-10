extern "C" {
  #include <system.h>
  #include <tty.h>
  #include <gdt.h>
  #include <idt.h>
  #include <irq.h>
  #include <timer.h>
  #include <keyboard.h>
  #include <string.h>
  void main();
  void idt_install();
}

#include <io.hpp>

void kmain();

namespace kernel {
  void init() {
    gdt_install();
    idt_install();
    isrs_install();
    irq_install();
    timer_install();
    keyboard_install();
    init_video();
  }
}
void kmain() {
  kernel::init();
  __asm__ __volatile__("sti");
/*  puts("hello kernel world!\n");
  puts("this is another line!\n");

  puts("type here: "); */
  io::writeln("hello kernel world!");
  io::writeln("this is another line!");
  io::write("type here: ");
  for(;;);
}

void main() {
  kmain();
}
