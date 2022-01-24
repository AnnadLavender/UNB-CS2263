#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{
  int value;
  int iErr;
  printf("Value to examine: ");
  iErr = scanf("%d",&value);
  if(value <= 0 || iErr != 1)
  {
    printf("Unable to read the value\n");
  }

  int i = 0;
  int count = 0;
  while(i <= value/2)
  {
    if(pow(2,i+1) > value && pow(2,i) <= value)
    {int j;
      for(j = i;j >= 0;j--)
      {
        if (pow(2,j) <= value)
        {
          value -=pow(2,j);
          count++;
        }
      }
    }
    i++;
  }
  printf("There are %d 1s",count);
  return 0;
}
