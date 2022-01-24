// arithmetic2. c
#include <stdio.h>
#include <stdlib.h>
int main ( int argc ,char * * argv )
{
  int arr[] = {10, 11, 12, 13, 14, 15, 16};
  int* apt = arr;
  int i;
  int length = sizeof(arr) / sizeof(int);

  for(i = 0; i < length; i++)
  {
    printf("%d\t%d\t%p\t%d\n", i, arr[i], apt, *apt);
    apt++;
  }
}
