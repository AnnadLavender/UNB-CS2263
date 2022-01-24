#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int clear(char* currentTag)
{
  int i = 0;
  while(*(currentTag + i) !='>' && *(currentTag + i) !=' ' && *(currentTag + i) !='/' && *(currentTag + i) !='\0')
  {
    i++;
  }

  if(*(currentTag + i) != '>')
  {
    *(currentTag + i) = '>';
    int countOpen = 1;
    while(countOpen)
    {
      i++;
      if(*(currentTag + i) == '\0')
      {
        break;
      }
      if(*(currentTag + i) == '<')
      {
        countOpen++;
      }
      else if(*(currentTag + i) == '>')
      {
        countOpen--;
      }
      *(currentTag + i) = ' ';
    }
  }
  return 0;
}

bool compare(char* string1, char* string2)
{
  int i = 0;
  while(*(string1 + i) != '>' && *(string2 + i) != '>')
  {
    if(*(string1 + i) != *(string2 + i))
    {
      return false;
    }
    i++;
  }
  return *(string1 + i) == *(string2 + i);
}

int getIndex(char *currentTag, char **tagNameArray, int tagArraySize)
{
  int i = 0;
  while(i < tagArraySize)
  {
    if(compare(currentTag, *(tagNameArray + i)))
    {
      return i;
    }
    i++;
  }
  return tagArraySize;
}

void print(char *string)
{
  int i = 1;
  while(*(string + i) != '>')
  {
    printf("%c", *(string + i));
    i++;
  }
  printf("\t");
}

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
void freeAll(char* input, char** nameTag, int* countTag)
{
  int i;
  free(input);
  for(i = 0; i< 100; i++)
  {
    free(nameTag[i]);
  }
  free(nameTag);
  free(countTag);
}
int main(int argc, char* argv[])
{
  FILE *file;
  char* inputArray = NULL;
  char **nameTag = NULL;
  int *countTag = NULL;

  inputArray = (char *)malloc(sizeof(char) * 100000);
  nameTag = (char **) malloc(sizeof(char *) * 100);
  countTag = (int *) malloc(sizeof(int) * 100);

  int pointer = 0;
  int j = 0;

  file = fopen(argv[1],"r");

  if(file == (FILE*)NULL)
  {
    fprintf(stderr, "Unable to open file %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  char c = fgetc(file);

  while(c != EOF)
  {
    *(inputArray + pointer) = c;
    pointer++;
    c = fgetc(file);
  }
  *(inputArray + pointer) = '\0';

  int tagArraySize = 0;
  for(pointer = 0; *(inputArray + pointer) != '\0'; pointer++)
  {
    if(*(inputArray + pointer) == '<' && *(inputArray + pointer + 1) == '!')
    {
      clear(inputArray + pointer);
    }
    else if(*(inputArray + pointer) == '<' && *(inputArray + pointer + 1) != '/' && *(inputArray + pointer + 1) != '\0')
    {
      clear(inputArray + pointer);
      int index = getIndex(inputArray + pointer, nameTag, tagArraySize);
      if(index == tagArraySize)
      {
        tagArraySize++;
        *(nameTag + index) = duplicateString(inputArray + pointer);
        *(countTag + index) = 1;
      }
      else
      {
        *(countTag + index) += 1;
      }
    }
  }

  pointer = 0;
  while(pointer < tagArraySize)
  {
    print(*(nameTag + pointer));
    printf("%d\n", *(countTag + pointer));
    pointer++;
  }

  fclose(file);
  freeAll(inputArray, nameTag, countTag);
  return EXIT_SUCCESS;
}
