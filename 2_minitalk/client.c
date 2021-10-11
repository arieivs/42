#include "minitalk.h"

void	send_message(char *str, pid_t to_pid)
{
	static int	server_pid = 0;
	static int	nr_bits = 0;
	static char	*message = NULL;
	static int	i = 0;

	if (to_pid)
	{
		write(1, "pid\n", 4);
		server_pid = to_pid;
	}
	if (str)
	{
		write(1, "str\n", 4);
		message = ft_strdup(str);
	}
	if (message[nr_bits / 8])
	{
		write(1, &message[nr_bits / 8], 1);
		ft_putnbr_fd(128 >> (nr_bits % 8), 1);
		if (message[nr_bits / 8] & (128 >> (nr_bits % 8)))
		{
			write(1, "1", 1);
			kill(server_pid, SIGUSR1);
		}
		else
		{
			write(1, "0", 1);
			kill(server_pid, SIGUSR2);
		}
		nr_bits++;
	}
	else
	{
		if (i < 8)
		{
			kill(server_pid, SIGUSR2);
			i++;
		}
		else
		{
			write(1, "end\n", 4);
		//free(message);
			exit(0);
		}
	}
}

static void sigusr_handler(int sig_num)
{
	if (sig_num == SIGUSR1)
		send_message(0, 0);
	// else if (sig_num == SIGUSR2)
		// error and exit
}

int	main(int ac, char **av)
{
	struct sigaction	sa;

	if (ac != 3)
	{
		write(1, "Please provide the server's PID and a message.\n", 47);
		return (0);
	}
	sa.sa_handler = &sigusr_handler;
	sigemptyset(&(sa.sa_mask));
	sigaddset(&(sa.sa_mask), SIGUSR1);
	sigaddset(&(sa.sa_mask), SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_message(av[2], ft_atoi(av[1]));
	while (1)
		pause();
	return (0);
}
