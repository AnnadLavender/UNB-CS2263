#ifndef STRINGS_H
#define STRINGS_H

typedef char* String;

String mallocString(int stringsize);
void freeString(String s);
String duplicateString(String s);
String* duplicateStringList(String* s,int n);
int compareStrings(void* s1, void* s2);

#endif
