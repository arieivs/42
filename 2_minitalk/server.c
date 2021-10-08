#include "minitalk.h"
#include <stdio.h>

static void	sigusr_handler(int sig_num, siginfo_t *info, void *context)
{
	int			client_pid;
	static int	nr_bits = 0;
	static char	c = 0;
	static char	*message = NULL;
	char		*tmp;
	(void)context;

	client_pid = info->si_pid;
	if (!message)
	{
		message = (char *)malloc(sizeof(char));
		message[0] = 0;
	}
	if (sig_num == SIGUSR1)
	{
		write(1, "1", 1);
		c = c | 1;
	}
	else if (sig_num == SIGUSR2)
	{
		write(1, "0", 1);
		c = c | 0;
	}
	nr_bits++;
	if (nr_bits >= 8)
	{
		if (c)
		{
			tmp = ft_strjoin(message, &c);
			free(message);
			message = tmp;
		}
		else
		{
			ft_putstr_fd(message, 1);
			free(message);
		}
		nr_bits = 0;
		c = 0;
	}
	else
		c = c << 1;
	printf(" pid: %d ", client_pid);
	kill(client_pid, SIGUSR1);
	// if kill returns -1, error
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = 0;
	sigemptyset(&(sa.sa_mask));
	sigaddset(&(sa.sa_mask), SIGUSR1);
	sigaddset(&(sa.sa_mask), SIGUSR2);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sigusr_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "PID: ", 5);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return(0);
}
	
