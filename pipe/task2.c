#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  int pd[2];
  pipe(pd);

  if (fork()) {
    close(1);
    dup(pd[1]);
    close(pd[0]);
    close(pd[1]);
    execlp(argv[1], argv[1], (char*)NULL);
  } else {
    close(0);
    dup(pd[0]);
    close(pd[0]);
    close(pd[1]);
    execlp(argv[2], argv[2], (char*)NULL);
  }

  return 0;
}
