// arithmetic13. c
#include <stdio.h>
#include <stdlib.h>
int arrindex (int * p1, int * p2)
{
  return (p2 - p1);
}
int main ( int argc ,char * * argv )
{
  int arr[] = {10, 11, 12, 13, 14, 15, 16};
  int i;
  for(i; i < sizeof(arr)/sizeof(arr[0]); i++)
  {
    printf("%d	%d\n", i, arrindex(&arr[0], &arr[i]));
  }
}
