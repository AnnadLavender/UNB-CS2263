#include <stdlib.h>
int isPrime(int i)
{
  if(i == 0 || i == 1 || i < 0)
  {
    return 0;
  }
  else if(i == 2)
  {
    return 1;
  }
  else
  {
    int j;
    for (j = 2; j < (i^(1/2)); j++)
    {
      if(i%j == 0)
      {
        return 0;
      }
    }
    return 1;
  }
}
