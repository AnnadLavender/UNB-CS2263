#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Strings.h"

void swap(void *x, void *y, int width)
{
  char* p = x;
  char* q = y;
  char temp;
  int i;
  for(i = 0; i < width; i++)
  {
    temp = p[i];
    p[i] = q[i];
    q[i] = temp;
  }
}

void selectionSort(void* arr, int n, int width,int(*comp)(void*, void*))
{
  int i=0,j;
  while(i<n)
  {
    int min = i;

    for(j = 1; j < n; j++)
    {
      if(comp((arr+min), (arr+j)) > 0)
      {
        min = j;
      }
    }
    swap((arr+min*width),(arr+i*width),width);
    i++;
  }
}

void print(String* arr, int size)
{
  int i;
  printf("hi\n");
  for (i=0; i < size; i++)
  {
    printf("%s\n", arr[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[])
{
  String a[] = {"let it go","hello world","let it do"};
  int size = sizeof(a)/sizeof(a[0]);
  print(a,size);
  selectionSort(a,size,sizeof(char*),compareStrings);
  print(a,size);
  freeStringList(a,size);
  return 0;
}
