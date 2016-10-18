#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd = open(argv[1], O_RDONLY);
  lseek(fd, atoi(argv[2]) - 1, SEEK_SET);
  
  int cnt;
  char buffer[20];
  while (cnt = read(fd, buffer, 20))
    write(1, buffer, cnt);

  return 0;

}
