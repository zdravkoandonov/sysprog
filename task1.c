#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc > 1) {
    int fdWrite = open(argv[1], O_WRONLY | O_CREAT, 0666);
    if (fdWrite == -1) {
      write(2, "Cannot open file", 16);
      return 1;
    }
    int fdRead = open(argv[1], O_RDONLY);
    if (fdRead == -1) {
      write(2, "Cannot open file", 16);
      return 1;
    }
    lseek(fdWrite, -1, SEEK_END);
    char c;
    while (read(fdRead, &c, 1)) {
      if (c >= '0' && c <= '9')
        break;
      write(fdWrite, &c, 1);
    }
    char buff[100];
    int readCount;
    while (readCount = read(fdRead, buff, 100))
        write(1, buff, readCount);
  } else {
    printf("No file name provided");
  }

  return 0;
}
