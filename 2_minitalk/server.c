#include "minitalk.h"

void	sigusr_handler(int sig_num)
{
	static int	nr_bits = 0;
	static char	c = 0;

	if (sig_num == SIGUSR1)
	{
		write(1, "1", 1);
		c = c | 1;
	}
	else
	{
		write(1, "0", 1);
		c = c | 0;
	}
	nr_bits++;
	if (nr_bits >= 8)
	{
		write(1, &c, 1);
		write(1, "\n", 1);
		nr_bits = 0;
		c = 0;
	}
	else
		c = c << 1;	
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = &sigusr_handler;
	sigemptyset(&(sa.sa_mask));
	sigaddset(&(sa.sa_mask), SIGUSR1);
	sigaddset(&(sa.sa_mask), SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	write(1, "\n", 1);
	return(0);
}
	
