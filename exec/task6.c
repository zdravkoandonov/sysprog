#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  close(1);
  open(argv[1], O_WRONLY | O_CREAT, 0666);

  execlp("grep", "grep", "abc", "ff", (char*)NULL);

  return 0;
}
