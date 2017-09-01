/* fileIO.h */


#ifndef __FILEIO_H__
#define __FILEIO_H__

int printf(const char *format, ...);
int fgetc(FILE *fp);
int fputc(int ch, FILE *fp);
int getchar();
int putchar(int ch);

char *fgets(char *s, int n, FILE *fp);
char *gets(char *s);
int fputs(const char *s, FILE *fp);
int puts(const char *s);

size_t fread(void *ptr, size_t size, size_t num, FILE *stream);
size_t fwrite(const void *ptr, size_t size, size_t num, FILE *strem);

void IO_copyChar();
void IO_copyStr();
void IO_copyRecord();


#endif
