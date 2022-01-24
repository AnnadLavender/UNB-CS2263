#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Strings.h"
typedef char* String;

String mallocString(int stringsize)
{
  return (String)malloc(sizeof(char)* (stringsize));
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
String* duplicateStringList(String* s,int n)
{
  String* slCopy;
  // Allocate the list
  slCopy = (String*)malloc(sizeof(String)*n);
  if(slCopy == (String*)NULL) return slCopy;
  int i,j;
  for(i = 0; i<n; i++)
  {
    slCopy[i] = duplicateString(s[i]);
    if(slCopy[i] == (String)NULL)
    {
      for(j=0; j<i; j++)
      {
        freeString(slCopy[j]);
      }
      free(slCopy);
      slCopy = (String*)NULL;
      break;
    }
  }
  return slCopy;
}

int compareStrings(void* s1, void* s2)
{
  return strcmp(s1,s2);
}

String getString(String terminators)
{
  String s;
  s = terminators;
  return s;
}
