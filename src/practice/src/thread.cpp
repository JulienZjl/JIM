/* thread.cpp */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "../include/thread.h"

void function_thread()
{
	int err;
	pthread_t tid;
	char buf1[20] = "This's child thread";
	char buf2[20] = "This's main thread";

	err = pthread_create(&tid, NULL, pthread1, NULL);

	if (err != 0)
	{
		perror("Thread fail!");
		exit(1);
	}

	printIDs(buf2);
}

void *pthread1(char *buf)
{
	printIDs(buf);

	return NULL;
}

void printIDs(char *buf)
{
	pid_t pid;
	pthread_t tid;

	pid = getpid();
	tid = pthread_self();

	printf("%s:pid = %u, tid = %u, 0x%x\n", buf, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
}
