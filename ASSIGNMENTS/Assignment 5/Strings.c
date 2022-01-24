#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Strings.h"

String mallocString(int stringsize)
{
  return (String)malloc(sizeof(char) * (stringsize + 1));
}

void freeString(String s)
{
  free(s);
}

String duplicateString(String s)
{
  String sCopy = mallocString(strlen(s));
  if(sCopy != (String)NULL)
  {
    strcpy(sCopy,s);
  }
  return sCopy;
}
