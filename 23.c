#include<stdio.h>
#include<unistd.h>

void main()
{
  long PIPE_BUF, OPEN_MAX;
  PIPE_BUF = pathconf(".", _PC_PIPE_BUF);
  OPEN_MAX = sysconf(_SC_OPEN_MAX);
  printf("Pipe_buf = %ld\t Open_max = %ld\n", PIPE_BUF, OPEN_MAX);
}
