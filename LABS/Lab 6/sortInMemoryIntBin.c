#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
char* decimalToBinary(int n)
{
  int i;
  static char binary[16];
  for(i = 15; i >= 0; i--)
  {
    if(n%2 == 0)
    {
      binary[i] = '0';
    }
    else
    {
      binary[i] = '1';
    }
    n/=2;
  }
  return binary;
}

int binaryToDecimal(char* n)
{
  int i, j=15;
  int decimal = 0;
  printf("hi\n");
  for(i = 0; i < 16; i++)
  {

    if(n[i] == '1')
    {
      decimal += pow(2,j);
    }
    j--;
  }
  return decimal;
}


int main(int argc, char* argv[])
{

  printf("%d",binaryToDecimal(bin));

  return EXIT_SUCCESS;
}
