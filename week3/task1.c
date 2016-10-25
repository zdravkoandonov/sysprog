#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  int fd = open(argv[1], O_WRONLY|O_CREAT, 0777);
  close(1);
  dup(fd);
  int i;
  for (i = 0; i < 10; ++i) {
    write(1, "EXAMPLE", 7);
  }

  return 0;
}
