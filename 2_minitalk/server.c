/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svieira <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:14:53 by svieira           #+#    #+#             */
/*   Updated: 2021/11/01 12:15:39 by svieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	server_error(int client_pid, char *message)
{
	if (message)
		free(message);
	kill(client_pid, SIGUSR2);
	write(1, "\nServer unexpected error.\n", 26);
	exit(EXIT_FAILURE);
}

static char	*build_message(char *message, char c)
{
	int		message_len;
	char	*tmp;
	int		i;

	if (!message)
	{
		message = (char *)malloc(sizeof(char));
		message[0] = 0;
	}
	message_len = ft_strlen(message);
	tmp = (char *)malloc(sizeof(char) * message_len + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (message[i])
	{
		tmp[i] = message[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = 0;
	free(message);
	return (tmp);
}

static char	*print_message(char *message)
{
	ft_putstr_fd(message, 1);
	free(message);
	return (NULL);
}

static void	sigusr_handler(int sig_num, siginfo_t *info, void *context)
{
	static int	client_pid = 0;
	static int	nr_bits = 0;
	static char	c = 0;
	static char	*message = NULL;

	(void)context;
	if (info->si_pid)
		client_pid = info->si_pid;
	if (sig_num != SIGUSR1 && sig_num != SIGUSR2)
		return ;
	if (sig_num == SIGUSR1)
		c |= 1;
	if (++nr_bits >= 8)
	{
		if (c)
			message = build_message(message, c);
		else
			message = print_message(message);
		nr_bits = 0;
		c = 0;
	}
	else
		c = c << 1;
	if (kill(client_pid, SIGUSR1) == -1)
		server_error(client_pid, message);
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
	return (0);
}
