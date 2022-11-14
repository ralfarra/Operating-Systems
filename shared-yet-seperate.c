#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


int main()
{
  int x = 5;
  printf("address & value of x in parent before fork: %p, %d\n", &x, x);

  pid_t child_pid = fork();

  if(child_pid == 0)
  {
    printf("address & value of x in child BEFORE changing values: %p, %d\n", &x, x);
    x = 10;
    printf("address & value of x in child AFTER changing values: %p, %d\n", &x, x);
  }

    printf("address & value of x in parent fork: %p, %d\n", &x, x);
    x = 11;
    printf("address & value of x in parent after changing the values: %p, %d\n", &x, x);

  return 1;

}
