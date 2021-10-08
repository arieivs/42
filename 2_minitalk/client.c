#include "minitalk.h"

void	send_char(int c, pid_t to_pid)
{
	int	ref;

	ref = 128;
	while (ref)
	{
		if (c & ref)
			kill(to_pid, SIGUSR1);
		else
			kill(to_pid, SIGUSR2);
		usleep(1);
		ref = ref >> 1;
	}
}

void	send_message(char *str, pid_t to_pid)
{
	int	i;

	i = 0;
	while(str[i])
	{
		send_char(str[i], to_pid);
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac != 3)
	{
		write(1, "Please provide the server's PID and a message.\n", 47);
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	send_message(av[2], server_pid);
	return (0);
}
