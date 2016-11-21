#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (argc > 1) {
    if (!fork()) {
      close(1);
      open("ftemp", O_WRONLY | O_CREAT | O_TRUNC, 0666);
      execlp("who", "who", (char*)NULL);
    } else {
      wait();
      if (!fork()) {
        close(1);
        open("fres", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        execlp("grep", "grep", argv[1], "ftemp", (char*) NULL);
      } else {
        wait();
        int fd = open("fres", O_RDONLY);
        char buf[10];
        if (read(fd, buf, 10) > 0)
          printf("Yes");
        else
          printf("No");
      }
    }
  } else {
    printf("No username provided");
  }

  return 0;
}
