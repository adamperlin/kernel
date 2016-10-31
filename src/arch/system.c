#include <system.h>

unsigned char *
memcpy(void *dest, const void *src, int count) {
//  if (src == NULL || dest == NULL) return NULL;
  const char *s = (const char*) src;
  char *d = (char *) dest;
  for (int i = 0; i < count; i++) {
    d[i] = s[i];
  }

  return dest;
}

unsigned char *
memset(void *dest, char val, int count) {
  /*if (dest == NULL) {
    return NULL;
  }*/
  char *dp = (char *) dest;
  for (int i = 0; i < count; i++) {
    dp[i] = val;
  }
  return dest;
}

unsigned short *
memsetw(unsigned short *dest, unsigned short val, int count) {
/*  if (dest == NULL) {
    return NULL;
  }*/
  for (int i = 0; i < count; i++) {
    dest[i] = val;
  }
  return dest;
}

int strlen(const char *str) {
  int len = 0;
  for (char *p = (char*) str; *p != '\0'; ++p) {
    len++;
  }
  return len;
}

unsigned char inportb(unsigned short _port) {
  unsigned char rv;
  __asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
  return rv;
}

void outportb(unsigned short _port, unsigned char _data) {
  __asm__ __volatile__("outb %1, %0" : : "dN" (_port), "a" (_data));
}
