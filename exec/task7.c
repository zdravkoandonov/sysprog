#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  if (!fork()) {
    close(1);
    open("fout", O_WRONLY | O_CREAT, 0666);
    execlp(argv[1], argv[1], (char*)NULL);
  }

  wait();
  execlp(argv[2], argv[2], (char*)NULL);

  return 0;
}
