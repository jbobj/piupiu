#ifndef UTIL_H
#define UTIL_H

//Functions to help C++ programmers not go crazy in C

// Allocate memory of size len and copy in pointer into it
void* deepcpy(const void* in, int len);

// Allocate and copy a new string
char* deepstrcpy(const char* in);

#endif
