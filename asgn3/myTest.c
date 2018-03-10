/*
 * Christopher Allan
 * Testing Module usage
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <assert.h>
#include <sys/wait.h>

int main(void) {  

  int fd;
  int sleep_len;
  ssize_t r;
  
  /* writing to device 0*/
  fd = open("/dev/sleepy0", O_RDWR);
  assert(fd != -1);

  sleep_len = 10;
  r = write(fd, &sleep_len, sizeof sleep_len);
  printf("write returned: %zd\n", r);
  assert(r >= 0);
  close(fd);
    
  return 0;
}
