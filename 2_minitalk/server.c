#include "minitalk.h"

void	sigusr1_handler(int sig_num)
{
	(void)sig_num;

	write(1, "1", 1);
}

void	sigusr2_handler(int sig_num)
{
	(void)sig_num;

	write(1, "0", 1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa1;
	struct sigaction	sa2;

	sa1.sa_handler = &sigusr1_handler;
	sigemptyset(&(sa1.sa_mask));
	sigaddset(&(sa1.sa_mask), SIGUSR1);
	sigaction(SIGUSR1, &sa1, NULL);
	sa2.sa_handler = &sigusr2_handler;
	sigemptyset(&(sa2.sa_mask));
	sigaddset(&(sa2.sa_mask), SIGUSR2);
	sigaction(SIGUSR2, &sa2, NULL);
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	write(1, "\n", 1);
	return(0);
}
	
