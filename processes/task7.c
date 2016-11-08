#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  fork();
  fork();
  fork();
  printf("%d %d\n", getpid(), getppid());
  wait(NULL);
  wait(NULL);
  wait(NULL);

  return 0;
}
