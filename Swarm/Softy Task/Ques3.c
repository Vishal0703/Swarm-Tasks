#include <stdio.h>
#include<stdlib.h>
#include <time.h>

int main()
{
  int n,i;
  scanf("%d", &n);
  printf("%d\n", n);

  srand(time(NULL));
  for(i=0; i<n;i++)
    {
      printf("%d\n", rand());
    }

}
