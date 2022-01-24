#include <stdlib.h>
int isFib(int i)
{
  if(i == 0 || i == 1)
  {
    return 1;
  }
  else if(i < 0)
  {
    return 0;
  }
  else
  {
    int a = 0;
    int b = 1;
    int c = a + b;
    while(c<=i)
    {
      if(i == c)
      {
        return 1;
      }
      a = b;
      b = c;
      c = a + b;
    }
    return 0;
  }
}
