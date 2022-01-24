#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fputString(FILE* pFOut, char* s)
{
  fprintf(pFOut, "%d ", strlen(s) - 1);
  fprintf(pFOut, "%s",s);
  return 1;
}
