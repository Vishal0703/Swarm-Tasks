#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
  setenv("THREADS", "mosh-mosh",1);
  system("echo $THREADS");
  unsetenv("THREADS");

}
