/* fileIO.cpp  */

#include <stdio.h>
#include <stdlib.h>
#include "../include/fileIO.h"

#define BUF_SIZE 10


int main1(int argc, char *argv[])
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


int main(int argc, char *argv[])
{
	printf("Copy file!!!\n");
	
	IO_copyFile();

	return 0;
}

void IO_copyFile()
{
	FILE *fp1, *fp2;
	char buf[BUF_SIZE];
	char *str = NULL;

	if ((fp1 = fopen("../hello", "r+")) == NULL)
	{
		printf("Open file '../a.txt' false!\n");
		exit(1);
	}

	if ((fp2 = fopen("../hello1", "w+")) == NULL)
	{
		printf("Open file '../b.txt' false!\n");
		exit(1);
	}

	while ((str = fgets(buf, BUF_SIZE, fp1)) != NULL)
	{
		fputs(str, fp2);
	}

	fclose(fp2);
	fclose(fp1);
}

