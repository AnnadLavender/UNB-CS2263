#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* mallocString(int stringsize)
{
  return (char*)malloc(sizeof(char)* (stringsize));
}

char* duplicateString(char* s)
{
  char* sCopy = mallocString(strlen(s));
  if(sCopy != (char*)NULL)
  {
    strcpy(sCopy,s);
  }
  return sCopy;
}

int main(int argc, char* argv[])
{
	char* output;
	output = duplicateString("Hello World");
	if(output == (char*)NULL)
  {
		fprintf(stderr,"Memory failure, terminating");
		return EXIT_FAILURE;
	}
	printf("%s\n", output);
	free(output);
  return EXIT_SUCCESS;
}
