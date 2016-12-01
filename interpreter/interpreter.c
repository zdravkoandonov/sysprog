#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
  while (1) {
    printf("%s", "\n$ ");
    char* buf;
    scanf("%ms", &buf);
    if (!fork())
      execlp(buf, buf, (char*)NULL);
    else
      wait(NULL);
  }


  return 0;
}
