#ifndef STRINGS_H
#define STRINGS_H
#include <string.h>
typedef char* String;

String mallocString(int stringsize);
void freeString(String s);
String duplicateString(String s);

#endif
