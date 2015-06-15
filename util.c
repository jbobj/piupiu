#include "util.h"
#include "stdlib.h"
#include "string.h"

void* deepcpy(const void* in, int len)
{
    void* mem = malloc(len);
    memcpy(mem, in, len);
    return mem;
}


char* deepstrcpy(const char* in)
{
    return (char*)deepcpy(in, strlen(in)+1);
}
