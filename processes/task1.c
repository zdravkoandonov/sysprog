#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int i = 0;
  if (fork()) {
    wait();
    i++;
    printf("in if %d %d\n", getpid(), getppid());
    printf("%d\n", i);
  } else {
    i--;
    printf("%d %d\n", getpid(), getppid());
    printf("%d\n", i);
  }
  i += 2;
  printf("%d\n", i);

  return 0;
}
