/* fileIO.cpp  */

#include <stdio.h>
#include <stdlib.h>
#include "../include/fileIO.h"

#define BUF_SIZE 10

typedef struct Record
{
	char name[10];
	int age;
}Message;


int main(int argc, char *argv[])
{
	printf("Copy file!!!\n");

	//IO_copyChar();
	
	//IO_copyStr();

	IO_copyRecord();

	return 0;
}


void IO_copyChar()
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
}


void IO_copyStr()
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

void IO_copyRecord()
{
	Message mess1[2];
	Message mess2[2] = {
	{"kyle", 26}, {"Julien", 27}
	};
	FILE *fp1, *fp2;

	if ((fp1 = fopen("../s.txt", "w+")) == NULL)
	{
		printf("Open s file error!!\n");
		exit(1);
	}

	fwrite(mess2, sizeof(Message), 2, fp1);
	
	fseek(fp1, 0L, SEEK_SET);
	
	fread(mess1, sizeof(Message), 2, fp1);
	
	fclose(fp1);
	
	if ((fp2 = fopen("../s1.txt", "w+")) == NULL)
	{
		printf("Open s1 file error!!\n");
		exit(1);
	}

	fwrite(mess1, sizeof(Message), 2, fp2);
	

	printf("%s, %d\n%s, %d\n", mess1[0].name, mess1[0].age, mess1[1].name, mess1[1].age);

	fclose(fp2);
}

