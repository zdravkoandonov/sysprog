#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
  printf("Father");
  if (!fork()) {
    write(1, "Child", 5);
    close(1);
    open(argv[1], O_WRONLY | O_CREAT, 0777);
    
    int i;
    for (i = 1; i <= 10; ++i) {
      printf("%d\n", i);
    }
    printf("asd");
  }
  printf("opq");
}
