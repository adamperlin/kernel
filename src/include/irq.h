#ifndef IRQ_H
#define IRQ_H

void irq_install_handler(int irq, void (*)(struct regs *));
void irq_uninstall_handler(int);
void irq_remap();
extern void irq_install();
//extern void irq_handler();

#endif
