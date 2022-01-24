#include <stdio.h>
#include <stdlib.h>
#include "Strings.h"

// copies the program name (argv[0]) to a new string, prints it out
int main(int argc, char* argv[])
{
	String programName;

	programName = duplicateString(argv[0]);
	if(programName == (String)NULL)
  {
		fprintf(stderr,"Memory failure, terminating");
		return EXIT_FAILURE;
	}
		printf("%s\n", programName);

	free(programName);

	return EXIT_SUCCESS;
}
