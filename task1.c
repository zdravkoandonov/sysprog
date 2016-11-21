#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc > 1) {
    int stdoutCopy = dup(1);
    close(1);
    int fdWrite = open(argv[1], O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fdWrite == -1) {
      write(2, "Cannot open file", 16);
      return 1;
    }
    close(0);
    int fdRead = open(argv[1], O_RDONLY);
    if (fdRead == -1) {
      write(2, "Cannot open file", 16);
      return 1;
    }
    char c;
    while (read(0, &c, 1) && !(c >= '0' && c <= '9')) {
      write(1, &c, 1);
    }
    char buff[100];
    int readCount;
    close(1);
    dup(stdoutCopy);
    while (readCount = read(0, buff, 100))
        write(1, buff, readCount);
  } else {
    printf("No file name provided");
  }

  return 0;
}
