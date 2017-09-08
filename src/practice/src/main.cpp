#include <stdio.h>
#include "../include/process.h"
//#include "../include/thread.h"

extern void function_thread();


int main(int argc, char *argv[])
{
	// fork
	//function_fork();

	//pipe
	//function_pipe();

	//alarm
	//function_alarm();

	//thread
	function_thread();
	
	return 0;
}
