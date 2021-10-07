#include "minitalk.h"

int	main(int ac, char **av)
{
	pid_t	server_pid;

	if (ac != 3)
	{
		write(1, "Please provide the server's PID and a message.\n", 47);
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	kill(server_pid, SIGUSR1);
	return (0);
}
