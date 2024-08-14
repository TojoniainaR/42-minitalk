/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: torandri <torandri@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 15:35:29 by torandri          #+#    #+#             */
/*   Updated: 2024/08/13 14:45:13 by torandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin_mod(char *s1, char c)
{
	size_t	i;
	char	*result;

	if (!s1)
		return (NULL);
	result = (char *)malloc (sizeof(char) * (ft_strlen(s1) + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	result[i++] = c;
	result[i] = '\0';
	free(s1);
	return (result);
}

void	ft_signal_handler(int signum, siginfo_t *info, void *context)
{
	static char		*message = NULL;
	static int		bit = 0;
	static int		character = 0;

	(void)info;
	(void)context;
	if (signum == SIGUSR1)
		character |= (1 << (7 - bit));
	bit++;
	if (message == NULL && character != '\0')
		message = ft_strdup("");
	if (bit == 8)
	{
		message = ft_strjoin_mod(message, character);
		if (character == '\0')
		{
			ft_printf("%s\n", message);
			free(message);
			message = NULL;
			kill(info->si_pid, SIGUSR2);
		}
		bit = 0;
		character = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;

	(void)argv;
	if (argc == 1)
	{
		sa.sa_sigaction = ft_signal_handler;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		ft_printf("PID : %d\n", getpid());
		while (1)
			pause();
	}
	else
		ft_putstr_fd("Error\nNo argument are required\n", 2);
	return (0);
}
