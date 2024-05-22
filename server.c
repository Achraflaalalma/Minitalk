/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:28:11 by alaalalm          #+#    #+#             */
/*   Updated: 2023/12/22 09:18:59 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	startup(void)
{
	ft_printf("%s  __    _      __                   _      \n", MAGNETA);
	ft_printf("%s / /   (_)____/ /_____  ___  ____  (_)___  \n", MAGNETA);
	ft_printf("%s/ /   / / ___/ __/ __ \\/ _ \\/ __ \\/ / __ \\ \n", WHITE);
	ft_printf("%s/ /___/ (__  ) /_/ / / /  __/ / / / / / / / \n", CYAN);
	ft_printf("%s/_____/_/____/\\__/_/ /_/\\___/_/ /_/_/_/ /_/  \n", MAGNETA);
	ft_printf("%s                                    /____/   \n", MAGNETA);
}

void	handle_char(char *the_char, int *index)
{
	ft_printf("%c", *the_char);
	*the_char = 0;
	*index = 7;
}

void	handle_sigl(int sig, siginfo_t *info, void *context)
{
	static pid_t			client_pid;
	static pid_t			curr_pid;
	static char				the_char;
	static int				i = 7;

	(void)context;
	if (!client_pid)
		client_pid = info->si_pid;
	curr_pid = info->si_pid;
	if (client_pid != curr_pid)
	{
		client_pid = curr_pid;
		the_char = 0;
		i = 7;
	}
	if (sig == SIGUSR1)
		the_char |= (0 << i);
	else if (sig == SIGUSR2)
		the_char |= (1 << i);
	i--;
	if (i < 0)
		handle_char(&the_char, &i);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &handle_sigl;
	sa.sa_flags = SA_SIGINFO;
	startup();
	ft_printf("%sServer is listnening at PID: %s%d\n", CYAN, WHITE, getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
	{
		pause();
	}
	return (0);
}
