#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Program2.h"

// a cover function for malloc()
// malloc and return memory for a string of stringsize characters
// return (char*)NULL on failure
char* mallocString(int stringsize)
{
  return (char*)malloc(sizeof(char)* (stringsize));
}

// just a cover function for free()
void freeString(char* s)
{
  free(s);
}

// create a duplicate string of s
// return it
// return (char*)NULL on failure
// should call mallocString(), and then strcpy()
char* duplicateString(char* s)
{
  char* sCopy = mallocString(strlen(s));
  if(sCopy != (char*)NULL)
  {
    strcpy(sCopy,s);
  }
  return sCopy;
}

char* fgetString(FILE* pFIn)
{
  int countChar = 0;
  char c = fgetc(pFIn);
  while(c != EOF)
  {
    countChar++;
    c = fgetc(pFIn);
  }
  fseek(pFIn, 0L, SEEK_SET);
  char* input = mallocString(countChar + 1);
  while(fgets(input, 100, pFIn) != NULL)
  {
    printf("%s", input);
  }
  return input;
}
