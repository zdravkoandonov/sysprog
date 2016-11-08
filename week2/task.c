#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd1, fd2;
  fd1 = open("f1", O_RDWR);
  fd2 = open("f1", O_RDWR);

  lseek(fd1, -5, SEEK_END);
  lseek(fd2, 4, SEEK_SET);

  write(fd1, "xyzw", 4);
  write(fd2, "12", 2);

  char buff[10];
  int count;
  lseek(fd1, 0, SEEK_SET);
  while (count = read(fd1, buff, 10))
    write(1, buff, count);

  close(fd1);
  close(fd2);

  return 0;
}
