#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

void	parent_sig_handler(int sig_num)
{
	(void)sig_num;

	write(1, "Parent: Received a response from child.\n", 40);
	exit(0);
}

void	child_sig_handler(int sig_num)
{
	(void)sig_num;

	write(1, "Child: Received a signal from parent.\n", 38);
	kill(getppid(), SIGUSR1);
	exit(0);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa_child;
	struct sigaction	sa_parent;

	sa_child.sa_handler = &child_sig_handler;
	sigaction(SIGUSR1, &sa_child, NULL);
	sa_parent.sa_handler = &parent_sig_handler;
	sigaction(SIGUSR1, &sa_parent, NULL);
	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		// fork returns 0: child process
		write(1, "Child: waiting for a sign from parent.\n", 39);
		// pause();
	}
	else
	{
		// fork returns child's pid: parent process
		write(1, "Parent: sending a sign to child.\n", 33);
		kill(pid, SIGUSR1);
		write(1, "Parent: sent, waiting for an answer from child.\n", 48);
		// pause();
	}
	return (0);
}
 
