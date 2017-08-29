#ifndef __FUNCTION_API__
#define __FUNCTION_API__

#define printf(fmt, args...)

void strcpy_J(char *des, const char *src);
char * strcpy_J2(char *dest, const char *src);
char * strncpy_J(char *dest, const char *src, size_t n);
char * memcpy_J(char *dest, const char *src, size_t n);

#endif
