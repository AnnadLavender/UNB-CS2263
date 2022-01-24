#include <stdio.h>
#include <stdlib.h>
void swap(int *xp, int *yp)
{
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionSort(int* arr, int n)
{
  int i,j;
  for(i = 0; i < n - 1; i++)
  {
    int min = i;

    for(j = i + 1; j < n; j++)
    {
      if(*(arr+min) > *(arr+j))
      {
        min = j;
      }
    }
    swap((arr+min),(arr+i));
  }
}

void print(int arr[], int size)
{
  int i;
  for (i=0; i < size; i++)
  {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(int argc, char* argv[])
{
  int a[] = {1,4,92,6,9,3,7};
  int size = sizeof(a)/sizeof(a[0]);
  print(a,size);
  selectionSort(a,size);
  print(a,size);
  return 0;
}
