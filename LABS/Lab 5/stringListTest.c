#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"

int main(int argc, char* argv[])
{
  String a[5];

  int size = 5;
  int i;
  printf("Input string: \n");
  for(i = 0; i < size;i++)
  {
    a[i] = mallocString(100);
    printf("a[%d]: \n",i);
    scanf("%99s", a[i]);
  }

  String* b = duplicateStringList(a,size);
  int i;
  for(i = 0; i < size; i++)
  {
    printf("a[%d]: %s\n",i,getString(a[i]));
    printf("b[%d]: %s\n",i,getString(*(b+i)));
    free(a[i]);
  }

  // a[4] = duplicateString(a[2]);
  // String* b = duplicateStringList(a,size);

	return EXIT_SUCCESS;
}
