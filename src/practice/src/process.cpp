/* process.cpp */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define msleep(x) usleep(x*1000)
#define BUFSIZE	20

void function_fork()
{
	pid_t pid;
	char *message = NULL;
	char str1[20] = "This is child!";
	char str2[20] = "This is parent!";
	int n;

	pid = fork();

	if (pid < 0)
	{
		perror("Fork false!\n");
		exit(1);
	}
	else if (pid == 0)
	{
		message = str1;
		n = 6;
	}
	else
	{
		message = str2;
		n = 3;
	}

	for ( ; n > 0; n--)
	{
		printf("%s\n", message);
		msleep(100);
	}
}

void function_pipe()
{
	char buf[BUFSIZE];
	pid_t pid;
	int fd[2], n;
	char str[] = "Hello world!";
	
	if (pipe(fd) < 0)
	{
		perror("Pipe false!\n");
		exit(0);
	}

	pid = fork();

	if (pid < 0)
	{
		perror("Fork false!\n");
		exit(0);
	}
	else if (pid > 0)
	{
		close(fd[0]);
		write(fd[1], str, sizeof(str));
		wait();
	}
	else
	{
		close(fd[1]);
		n = read(fd[0], buf, BUFSIZE);
		write(STDOUT_FILENO, buf, n);
		sleep(1);
	}

}
