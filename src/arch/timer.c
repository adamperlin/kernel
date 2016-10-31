#include <system.h>
#include <irq.h>
#include <tty.h>
/*constant to determine the number of interrupts
the interrupt timer should fire per second*/
#define TIMER_HZ 100
void timer_phase(int);

void timer_phase(int hz) {
  int divisor = 1193180 / hz;
  outportb(0x43, 0x36);
  outportb(0x40, divisor & 0xff);
  outportb(0x40, divisor >> 8);
}

int timer_ticks = 0;

void timer_handler(struct regs *r) {
  timer_ticks++;
  if (timer_ticks % TIMER_HZ == 0) {
  //  puts("one second passed!");
  }
}

void timer_install() {
  timer_phase(TIMER_HZ); //set timer interrupt firing to 100 hz = 100 ticks / second
  irq_install_handler(0, timer_handler);
}

void timer_wait(int ticks) {
  unsigned long end_ticks = timer_ticks + ticks;
  while(timer_ticks < end_ticks);
}
