#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int fputString(FILE* pFOut, char* s);
int main(int argc, char* argv[])
{
  FILE* fileRead;
  FILE* fileWrite;
  char string[2][100];

  fileRead = fopen(argv[1], "r");
  if(fileRead == (FILE*)NULL)
  {
    fprintf(stderr, "Unable to open file %s\n",argv[1]);
    return EXIT_FAILURE;
  }

  fileWrite = fopen(argv[2], "w");
  if(fileWrite == (FILE*)NULL)
  {
    fprintf(stderr, "Unable to open file %s\n",argv[2]);
    return EXIT_FAILURE;
  }
  int i = 0;
  char c;
  while(i < 2)
  {
    if(fgets(string[i],100,fileRead) != NULL)
    {
      printf("Done\n");
      i++;
    };
  }

  i = 0;
  while(i < 2)
  {
    fputString(fileWrite,string[i]);
    i++;
  }

  fclose(fileRead);
  fclose(fileWrite);
	return EXIT_SUCCESS;
}
