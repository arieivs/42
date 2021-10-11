#include "minitalk.h"

static void	server_error(int client_pid, char *message)
{
	if (message)
		free(message);
	kill(client_pid, SIGUSR2);
	write(1, "\nServer unexpected error.\n", 26);
	exit(EXIT_FAILURE);
}

static void	sigusr_handler(int sig_num, siginfo_t *info, void *context)
{
	static int	client_pid = 0;
	static int	nr_bits = 0;
	static char	c = 0;
	static char	*message = NULL;
	char		*tmp;
	(void)context;

	if (info->si_pid)
		client_pid = info->si_pid;
	if (!message)
	{
		message = (char *)malloc(sizeof(char));
		message[0] = 0;
	}
	if (sig_num != SIGUSR1 && sig_num != SIGUSR2)
		return ;
	if (sig_num == SIGUSR1)
	{
		//write(1, "1", 1);
		c |= 1;
	}
	/*else if (sig_num == SIGUSR2)
	{
		//write(1, "0", 1);
		c = c | 0;
	}*/
	nr_bits++;
	if (nr_bits >= 8)
	{
		if (c)
		{
			//write(1, "adding ", 6);
			//write(1, &c, 1);
			tmp = ft_strjoin(message, &c);
			free(message);
			message = tmp;
		}
		else
		{
			//write(1, "message: ", 9);
			ft_putstr_fd(message, 1);
			message = NULL;
			free(message);
		}
		nr_bits = 0;
		c = 0;
	}
	else
	{
		//write(1, "shift ", 6);
		c = c << 1;
	}
	//write(1, "pid ", 4);
	//ft_putnbr_fd(client_pid, 1);
	//write(1, "\n", 1);
	if (kill(client_pid, SIGUSR1) == -1)
		server_error(client_pid, message);
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
	
