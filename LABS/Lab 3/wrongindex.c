/*
* wrongindex . c
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main (int argc , char * * argv)
{
  int x = -2;
  int arr [] = {0 , 1 , 2 , 3 , 4};
  int y = 15;

  int i;

  printf ("&y = %p \n", &y);
  for(i = 0; i < sizeof(arr) / sizeof(int);i++)
  {
    printf ("&arr[%d] = %p\n",i, &arr[i]);
  }
  printf ("&x = %p \n", &x);
  printf("\n");
  printf ("\n&x = %p , &y = % p \n", &x , &y);
  printf ("x = %d , y = % d \n", x , y);
  arr [ -1] = 7;
  arr [5] = -23;
  printf ("&arr[%d] = %p\n",-1, &arr[-1]);
  printf ("&arr[%d] = %p\n",5, &arr[5]);
  printf ("\n&x = %p , &y = % p \n", &x , &y);
  printf ("x = %d , y = % d \n", x , y);
  arr [6] = 108;
  printf ("&arr[%d] = %p\n",6, &arr[6]);
  printf ("\n&x = %p , &y = % p \n", &x , &y);
  printf ("x = %d , y = % d \n", x , y);
  arr [7] = -353;
  printf ("&arr[%d] = %p\n",7, &arr[7]);
  printf ("\n&x = %p , &y = % p \n", &x , &y);
  printf ("x = %d , y = % d \n", x , y);

  return EXIT_SUCCESS;
}
