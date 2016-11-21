#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int i;
  for (i = 0; i < 5; ++i)
    if (!fork())
      execl("/usr/bin/who", "/usr/bin/who", (char*)NULL);
  if (!fork()) {
    execl("/usr/bin/who", "/usr/bin/who", (char*)NULL);
  }
  else {
    wait();
    printf("PRINTF\n");
  }


  return 0;
}
