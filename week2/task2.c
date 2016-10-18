#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd1 = open("fff", O_RDONLY|O_CREAT, 0777);
  int fd2 = open("fff", O_WRONLY);
  int fd3 = open("fff", O_RDWR);

  write(fd2, "hello world", 11);
  char buff[20];
  read(fd3, buff, 6);
  write(1, buff, 6);

  int cnt = read(fd1, buff, 5);
  write(1, buff, cnt);

  write(fd3, "chil", 4);
  write(fd2, "!!!", 3);

  read(fd1, buff, 9);
  write(1, buff, 9);

  close(fd1);
  close(fd2);
  close(fd3);

  return 0;
}
