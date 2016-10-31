#include <keyboard_map.h>
#include <keyboard.h>
#include <irq.h>
#include <bool.h>

void handle_special_keys(int);
bool shift = false;

void keyboard_handler(struct regs *r) {
  unsigned char scancode;
  scancode = inportb(0x60);

  if (scancode & 0x80) { // if key was released
    int original = get_original_key(scancode);
    if (original == 0x2A || original == 0x36) {
      shift = false;
    }
  } else if (scancode == 0x2A || scancode == 0x36) {
      shift = true;
  } else {
    if (shift) {
      handle_special_keys(scancode);
      putch(kbshift[scancode]);
    } else {
      handle_special_keys(scancode);
      putch(kbdus[scancode]);
    }
  }
}

void keyboard_install() {
  irq_install_handler(1, keyboard_handler);
}

int get_original_key(int scancode) {
  return scancode & 0x7f; //remove most significant bit to get original key...
}

bool key_released(int key) {
  return (key & 0x80);
}

void handle_special_keys(int key) {
  switch (key) {
    case 0x0E:
      putch('\b');
      putch(' ');
  }
}
