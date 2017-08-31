/* fileIO.cpp  */

#include <stdio.h>
#include <stdlib.h>
#include "../include/fileIO.h"

int main(int argc, char *argv[])
{
	FILE *fp;
	int ch;

	if ((fp = fopen("../a.txt", "a+")) == NULL)
	{
		printf("Open file false!!\n");
		exit(1);
	}

	while ((ch = getchar()) != EOF)
	{
		fputc(ch, fp);
	}
//	rewind(fp);
	fseek(fp, 0L, SEEK_SET);
	while ((ch = fgetc(fp)) != EOF)
	{
		putchar(ch);
	}

	fclose(fp);	

	return 0;
}
