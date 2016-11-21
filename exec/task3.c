#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {

  close(1);
  open("comout", O_WRONLY | O_CREAT, 0666);
  execvp(argv[1], &argv[1]);

  return 0;
}
