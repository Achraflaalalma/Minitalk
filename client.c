/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaalalm <alaalalm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:28:22 by alaalalm          #+#    #+#             */
/*   Updated: 2023/12/29 15:02:16 by alaalalm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <ctype.h>

void	startup(void)
{
	ft_printf("%s       .__  .__               __   \n,", MAGNETA);
	ft_printf("%s  ____ |  | |__| ____   _____/  |_ \n,", MAGNETA);
	ft_printf("%s_/ ___\\|  | |  |/ __ \\ /    \\   __\\ \n,", WHITE);
	ft_printf("%s\\  \\___|  |_|  \\  ___/|   |  \\  |  \n,", CYAN);
	ft_printf("%s \\___  >____/__|\\___  >___|  /__|  \n,", MAGNETA);
	ft_printf("%s     \\/             \\/     \\/      \n,", MAGNETA);
}

void	sigerror(void)
{
	ft_printf("%sSignal Error%s\n", RED, END);
	exit(EXIT_FAILURE);
}

void	send_signals(char *str, pid_t *srv_pid)
{
	int				i;
	int				start;
	char			ch;

	start = 0;
	while (str[start])
	{
		i = 7;
		ch = str[start];
		while (i >= 0)
		{
			if (((ch >> i) & 1) == 0)
			{
				if (kill(*srv_pid, SIGUSR1) == -1)
					sigerror();
			}
			else if (kill(*srv_pid, SIGUSR2) == -1)
				sigerror();
			i--;
			usleep(300);
		}
		start++;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	srv_pid;
	char	*str;
	char	*check_d;

	check_d = argv[1];
	if (argc == 3 && ft_digit(check_d) && (argv[1][0]) != '0')
	{
		srv_pid = ft_atoi(argv[1]);
		str = argv[2];
		startup();
		send_signals(str, &srv_pid);
	}
	else
		ft_printf("%sERROR%s ./client <Server_pid> <String>\n", REDBOX, END);
	return (0);
}
