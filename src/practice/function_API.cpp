/* Function API */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "function_API.h"

int main_1(int argc, char * argv[])
{
	char str1[10] = "01ABCDEF";
	char str2[10];
	char *str = str1;

	printf("str : %s\n", str);

	//strcpy_J(str2, str1);
	printf("str1 : %s \nstr2 copy after : %s\n", str1, str2);

	//strcpy_J2(str2, str1);
	printf("str1 : %s \nstr2 copy after : %s\n", str1, str2);

	//strncpy_J(str2, str1, 5);
	printf("str1 : %s \nstr2 copy after : %s\n", str1, str2);

	memcpy_J(str2, str1, 6);
	printf("str1 : %s \nstr2 copy after : %s\n", str1, str2);
	
	return 0;
}

void strcpy_J(char *des, const char *src)
{
	int i = 0;
	
	while (src[i])
	{
		des[i] = src[i];
		printf("des[%d] = %c\n", i, des[i]);
		i++;
	}
	des[i-1] = '\0';
}

char * strncpy_J(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; (i<n) && (src[n]!='\0'); i++)
	{
		dest[i] = src[i];
	}
	for ( ; i < n; i++)
	{
		dest[i] = '\0';
	}

	return dest;
}

char *strcpy_J2(char *dest, const char *src)
{
	assert((dest != NULL) && (src != NULL));

	char *strTmp = dest;

	while ((*dest++ = *src++) != '\0');

	return strTmp;
}

char *memcpy_J(char *dest, const char *src, size_t n)
{
	char *destStr = dest;
	const char *srcStr = src;

	while(n--)
	{
		*destStr++ = *srcStr++;
	}

	return destStr;
}

int main(int argc, char *argv[])
{
	typedef struct
	{
		int num;
		char *message;
	}Unit_t;

	Unit_t *p = malloc(sizeof(Unit_t));
	if (p == NULL)
	{
		printf("Out of memory!!\n");
		exit(1);
	}

	p->num = 2;
	p->message = malloc(20);
	strcpy(p->message, "Hello world");

	printf("num = %d,\tmessage = %s\n", p->num, p->message);

	free(p->message);
	free(p);
	p = NULL;
	
	return 0;
}

