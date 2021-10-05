#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
	int	pid;

	printf("Before forking\n");
	pid = fork();
	if (pid == 0)
	{
		printf("In the child process\n");
		printf("Child PID: %d | Parent PID: %d\n", getpid(), getppid());
	}
	else
	{
		printf("In the parent process\n");
		printf("Child PID: %d | Parent PID: %d | Grandpa PID: %d\n", pid, getpid(), getppid());
	}
	printf("After forking\n");
	return(0);
}
