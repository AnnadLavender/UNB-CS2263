#include <stdio.h>
#include <stdlib.h>
int isPrime(int i);

int main(int argc, char ** argv)
{
  int value;
  printf("Input the value you want to check: ");
  int check = scanf("%d", &value);
  if(check != 1)
  {
    printf("Unable to read the value\n");
    return EXIT_FAILURE;
  }
  if(isPrime(value) == 1)
  {
    printf("%d is a prime\n", value);
  }
  else
  {
    printf("%d is not a prime\n", value);
  }
  return EXIT_SUCCESS;
}
