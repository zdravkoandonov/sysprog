#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int i = 0;
  for (i = 0; i < 10; ++i) {
    write(1, "EXAMPLE\n", 8);
  }
  int stdout_copy = dup(1);
  close(1);
  int fd = open("fff", O_WRONLY|O_CREAT, 0777);

  for (i = 0; i < 10; ++i) {
    printf("%d\n", i);
  }

  fflush(stdout);
  dup2(stdout_copy, 1);
  for (i = 0; i < 10; ++i) {
    write(1, "HELLO\n", 6);
  }

  return 0;
}
