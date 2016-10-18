#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int fd1 = open("fff2", O_RDONLY|O_CREAT, 0777);  
  int fd2 = open("fff2", O_WRONLY);  
  int fd3 = open("fff2", O_RDWR);  

  write(fd3, "hello", 5);
  write(fd2, "worlds", 6);
  
  char buffer[20];
  read(fd1, buffer, 6);
  write(1, buffer, 6);

  close(fd2);

  write(fd3, "oops", 4);

  read(fd1, buffer, 6);
  write(1, buffer, 6);

  close(fd1);
  close(fd3);

  return 0;
}
