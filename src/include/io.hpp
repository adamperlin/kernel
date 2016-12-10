extern "C" {
  #include <tty.h>
}

namespace io {
  static unsigned char *newline = reinterpret_cast<unsigned char*>(const_cast<char*>("\n"));
  void writeln(const char *str) {
    puts(reinterpret_cast<unsigned char*>(const_cast<char*>(str)));
    puts(newline);
  }

  void write(const char *str) {
    puts(reinterpret_cast<unsigned char*>(const_cast<char*>(str)));
  }

  void format(unsigned char *str, const unsigned char *fmt, ...) {
    return;
  }
}
