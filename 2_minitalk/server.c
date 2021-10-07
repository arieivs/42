#include "minitalk.h"

void	server_sig_handler(int sig_num)
{
	(void)sig_num;
	struct sigaction	sa;
	
	sa.sa_handler = &server_sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	write(1, "Signal received!\n", 17);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	sa.sa_handler = &server_sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	pid = getpid();
	write(1, "PID: ", 5);
	ft_putnbr_fd(pid, 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return(0);
}
	
