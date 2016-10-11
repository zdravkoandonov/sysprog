#include <stdio.h>
#include <fcntl.h>

int main() {
  int fd = open("testfile", O_RDONLY);
  int readCount;
  char buffer[10];
  while (readCount = read(fd, buffer, 10)) {
    printf("%d\n", readCount);
  }

  return 0;
}
