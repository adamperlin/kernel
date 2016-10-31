#ifndef STRING_H
#define STRING_H

char *itoa(int num, char *str, int base) {
  bool neg = false;
  int i = 0;
  if (num == 0) {
    return "0\0";
  }

  while (num != 0) {
    int rem = num % base;
    str[i] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
    i++;
  }
  if (neg) {
    str[i++] = '-';
  }

  str[i] = '\0';
  strrev(str);
  return str;
}
