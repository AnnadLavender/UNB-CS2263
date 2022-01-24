#include <stdio.h>
#include <stdlib.h>
#include "Program2.h"

int main(int argc, char* argv[])
{
  FILE *file;
  if(argc != 2)
  {
    return EXIT_FAILURE;
  }
  file = fopen(argv[1], "r");
  if(file == (FILE*) NULL)
  {
    fprintf(stderr,"file %s not found\n", argv[1]);
    return EXIT_FAILURE;
  }
  fgetString(file);
  fclose(file);
}
