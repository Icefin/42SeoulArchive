#include <unistd.h>
#include <signal.h>

#include <stdio.h>

int main()
{ 
	int pid = getpid();
	printf("Server's PID is : %d\n", pid);
	while (1) ;
	return (0);
}