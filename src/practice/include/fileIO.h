/* fileIO.h */


#ifndef __FILEIO_H__
#define __FILEIO_H__

int fgetc(FILE *fp);
int fputc(int ch, FILE *fp);
int getchar();
int putchar(int ch);

char *fgets(char *s, int n, FILE *fp);
char *gets(char *s);
int fputs(const char *s, FILE *fp);
int puts(const char *s);

void IO_copyFile();


#endif
