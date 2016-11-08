#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd = open("fff", O_WRONLY | O_CREAT, 0777);
  if (fork()) {
    write(fd, "Hello", 5);
  } else {
    write(fd, "Hello", 5);
  }

  return 0;
}
