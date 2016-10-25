#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  int fdIn = open(argv[1], O_RDONLY);
  int fdOut = open(argv[2], O_WRONLY|O_CREAT, 0777);

  dup2(fdIn, 0);
  dup2(fdOut, 1);

  int readCount;
  char buffer[20];
  while (readCount = read(0, buffer, 20)) {
    write(1, buffer, readCount);
  }

  return 0;
}
