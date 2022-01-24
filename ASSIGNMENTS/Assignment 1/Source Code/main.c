#include <stdio.h>
#include <stdlib.h>
int isPrime(int i);
int isFib(int i);

int main(int argc, char **argv)
{
  int x1;
  int x2;
  int i;
  printf("Input the beginning of the range: ");
  int check1 = scanf("%d", &x1);

  printf("Input the ending of the range: ");
  int check2 = scanf("%d", &x2);

  if(check1 != 1 || check2 != 1)
  {
    printf("Unable to read the value\n");
    return EXIT_FAILURE;
  }
  printf("List of Fibonacci Primes: ");
  for(i = x1; i <= x2; i++)
  {
    if(isPrime(i) == 1 && isFib(i) == 1)
    {
      printf("%d\t", i);
    }
  }printf("\n");
  return EXIT_SUCCESS;
}
