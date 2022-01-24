#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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

int main(int argc, char* argv[])
{
  srand(time(0));
  int i,j;
  int quantity = atoi(argv[1]);
  FILE* fileWrite = fopen(argv[2], "wb");
  char* test = "Hello World";
  fwrite(test,sizeof(char), strlen(test),fileWrite);
  fwrite(decimalToBinary(quantity),sizeof(char), strlen(decimalToBinary(quantity)),fileWrite);
  for(j = 0; j < quantity; j++)
  {

    int value = rand()%quantity;
    char* output = decimalToBinary(value);
    fwrite(output,sizeof(char), strlen(output),fileWrite);
  }
  fclose(fileWrite);

  return EXIT_SUCCESS;
}
