#include <string.h>
#include <bool.h>
#include <tty.h>

char *strncpy (char *dest, const char *src, int n) {
  if (dest == NULL || src == NULL) {
    puts("NULL!!!");
    return NULL;
  }
  int i = 0;
  while (src[i] != '\0' && i < n) {
    dest[i] = src[i];
    i++;
  }
  if (i == n && src[i] == '\0') {
    dest[i] = '\0';
    return dest;
  } else if (i == n && src[i] != '\0') {
    return dest;
  } else {
    for (; i < n; i++) {
      dest[i] = 0;
    }
    return dest;
  }
}

char *itoa(int num, char *str, int base) {
  bool neg = false;

  int i = 0;
  if (num == 0) {
    str[i++] = 0;
    str[i] = '\0';
  }

  if (num < 0 && base == 10) {
    neg = true;
    num = -num;
  }

  while (num != 0) {
    int rem = num % base;
    str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
    num /= base;
  }
  if (neg) {
    str[i++] = '-';
  }

  str[i] = '\0';
  strrev(str);

  return str;
}

char *strrev(char *str) {
  int len = strlen(str);
	char temp[len + 1];
	strncpy(temp, str, len);
	if (str == NULL) {
   		 puts("error\n");
       return NULL;
	}
	int index = 0;
	for (int i = len - 1; i >= 0; i--) {
		str[i] = temp[index];
	  index++;
	}
  return str;
}
