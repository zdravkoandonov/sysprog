#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int pd[2];
  pipe(pd);

  if (fork()) {
    close(1);
    dup(pd[1]);
    close(pd[0]);
    close(pd[1]);
    execlp("ls", "ls", (char*)NULL);
  } else {
    close(0);
    dup(pd[0]);
    close(pd[0]);
    close(pd[1]);
    execlp("wc", "wc", (char*)NULL);
  }

  return 0;
}
