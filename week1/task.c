#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  int f;
  if (argc > 1)
    f = open(argv[1], O_RDONLY);
  else
    f = open("aa", O_RDONLY);
  int i, readCount;
  char buffer[5];

  for(i = 5; i >= 1; --i) {
    execlp("wc", "wc", "-l", "aa", 0);
    lseek(f, -3, SEEK_END);
    readCount = read(f, buffer, i);
    write(1, buffer, readCount);
  }

  return 0;
}
