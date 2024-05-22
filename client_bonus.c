/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:29:26 by alaalalm          #+#    #+#             */
/*   Updated: 2023/12/29 15:28:57 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	startup(void)
{
	ft_printf("%s       .__  .__               __   \n,", MAGNETA);
	ft_printf("%s  ____ |  | |__| ____   _____/  |_ \n,", MAGNETA);
	ft_printf("%s_/ ___\\|  | |  |/ __ \\ /    \\   __\\ \n,", WHITE);
	ft_printf("%s\\  \\___|  |_|  \\  ___/|   |  \\  |  \n,", CYAN);
	ft_printf("%s \\___  >____/__|\\___  >___|  /__|  \n,", MAGNETA);
	ft_printf("%s     \\/             \\/     \\/      \n,", MAGNETA);
}

void	server_received(int sig)
{
	(void)sig;
	ft_printf("%sMessage deliverd successfully%s\n", GREEN, END);
}

void	sigerror(void)
{
	ft_printf("%sClient Signal Error%s\n", RED, END);
	exit(EXIT_FAILURE);
}

void	send_signals(char c, pid_t srv_pid)
{
	int		i;
	char	ch;

	i = 7;
	ch = c;
	while (i >= 0)
	{
		if (((ch >> i) & 1) == 0)
		{
			if (kill(srv_pid, SIGUSR1) == -1)
				sigerror();
		}
		else if (kill(srv_pid, SIGUSR2) == -1)
			sigerror();
		i--;
		usleep(300);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	srv_pid;
	char	*str;
	char	*check_d;
	int		start;

	check_d = argv[1];
	if (argc == 3 && ft_digit(check_d) && (argv[1][0]) != '0')
	{
		srv_pid = ft_atoi(argv[1]);
		str = argv[2];
		startup();
		ft_printf("%sSending message ...%s\n", GREEN, END);
		signal(SIGUSR2, server_received);
		start = 0;
		while (str[start])
		{
			send_signals(str[start], srv_pid);
			start++;
		}
		send_signals('\0', srv_pid);
	}
	else
		ft_printf("%sERROR%s ./client <Server_pid> <String>\n", REDBOX, END);
	return (0);
}
