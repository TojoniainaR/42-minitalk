/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:27:06 by torandri          #+#    #+#             */
/*   Updated: 2024/08/13 14:34:57 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_signal = 0;

void	ft_signal_receiver(int signum, siginfo_t *info, void *context)
{
	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		g_signal = 1;
}

void	ft_send_signal(int pid, char character)
{
	static int	bit;
	int			sig;

	bit = 0;
	while (bit < 8)
	{
		if (character & (1 << (7 - bit)))
			sig = kill(pid, SIGUSR1);
		else
			sig = kill(pid, SIGUSR2);
		usleep(100);
		if (sig < 0)
		{
			ft_putstr_fd("Error\nBad PID\n", 2);
			exit (1);
		}
		while (g_signal == 0)
			usleep(100);
		g_signal = 0;
		bit++;
	}
}

void	ft_send_message(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		ft_send_signal(pid, message[i]);
		while (g_signal == 1)
			usleep(100);
		g_signal = 0;
		i++;
	}
	ft_send_signal(pid, '\0');
}

int	main(int argc, char *argv[])
{
	int					pid;
	char				*message;
	struct sigaction	sa;

	if (argc == 3)
	{
		sa.sa_sigaction = ft_signal_receiver;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		pid = ft_atoi(argv[1]);
		if (ft_check_error(pid, argv) == 1)
			return (1);
		message = argv[2];
		ft_send_message(message, pid);
	}
	else
		ft_putstr_fd("Error\nUsage : ./client PID_SERVER STRING_TO_PASS\n", 2);
	return (0);
}
