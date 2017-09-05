/*  OS_IO.cpp */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include "../include/OS_IO.h"

int main(int argc, char *argv[])
{
	//IOfunction_RW();

	IOfunction_nonblock();

	return 0;
}

void IOfunction_RW()
{
	char buf[10];
	int n;

	n = read(STDIN_FILENO, buf, 10);
	if (n < 0)
	{
		printf("Read file!\n");
		exit(1);
	}

	write(STDOUT_FILENO, buf, n);
}

void IOfunction_nonblock()
{
	char buf[10];
	int n, fp;

	fp = open("/dev/tty", O_RDONLY | O_NONBLOCK);
	if (fp < 0)
	{
		perror("Open /dev/tty");
		exit(1);
	}

	n = read(fp, buf, 10);

TRYAGAIN:
	if (n < 0)
	{
		if (errno == EAGAIN)
		{
			sleep(1);
			write(STDOUT_FILENO, "try again", strlen("try again"));
			goto TRYAGAIN;
		}

		perror("Read /dev/tty");
		exit(1);
	}

	write(STDOUT_FILENO, buf, 10);
	close(fp);
}