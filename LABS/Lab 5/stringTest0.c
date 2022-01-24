#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Strings.h"

int main(int argc, char ** argv)
{
  String a[5]= {"Hello World", "Hello Rick","Hello You", "Hello Mom"};
  int size = sizeof(a)/sizeof(a[0]);
  a[4] = duplicateString(a[2]);
  String* b = duplicateStringList(a,size);
  int i;
  for(i = 0; i < size; i++)
  {
    printf("a[%d]: %s\n",i,getString(a[i]));
    printf("b[%d]: %s\n",i,getString(*(b+i)));
    if(compareStrings(a[i],*(b+i)) == 0)
    {
      printf("Same\n");
    }
    else
    {
      printf("Different\n");
    }
  }
  for(i = 0;i < size;i++)
  {
    freeString(a[i]);
    freeString(*(b+i));
  }
  // free(a);
  free(b);
  return EXIT_SUCCESS;
}
