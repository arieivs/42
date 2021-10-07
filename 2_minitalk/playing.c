#include <sys/types.h> // pid_t type, amongst others
#include <unistd.h> // getpid() & co
#include <signal.h> // kill() & signal()
#include <stdlib.h> // exit()
#include <stdio.h>

void	catch_alarm(int	sig_num)
{
	(void)sig_num;

	printf("Timed out, exiting...\n");
	exit(0);
}

void	catch_int(int sig_num)
{
	(void)sig_num;

	// reset signal handler for next time -> but will there be a next time?
	// signal(SIGINT, catch_int);
	printf("Interrupting\n");
	exit(0);
}

void	terminating(void)
{
	int pid;

	pid = getpid();
	printf("Before terminating\n");
	kill(pid, SIGTERM);
	printf("After terminating\n");
}

void	parent_child(void)
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
}

int main(void)
{
	char	user[10];

	signal(SIGALRM, catch_alarm);
	signal(SIGINT, catch_int);
	// sleep(10);
	alarm(10);
	gets(user);
	alarm(0);
	parent_child();
	terminating();
	return(0);
}
