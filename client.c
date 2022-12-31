/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:34:12 by mkhalil           #+#    #+#             */
/*   Updated: 2022/12/31 13:50:09 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && ft_isdigit(str[i]))
		i++;
	if (str[i] == '\0' && i > 0)
		return (1);
	else
	{
		ft_putstr_fd("client: invalid process ID!\n", 1);
		return (0);
	}
}

static void	send_char(int pid, int c)
{
	int	bit;

	bit = 0x80;
	while (bit > 0)
	{
		if (c & bit)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit = bit >> 1;
	}
}

int	main(int ac, char **av)
{
	int	i;
	int	pid;

	if (ac != 3)
	{
		ft_putstr_fd("client: invalid number of arguments!\n", 1);
		return (0);
	}
	if (!check_pid(av[1]))
		return (0);
	pid = ft_atoi(av[1]);
	i = 0;
	while (av[2][i] != '\0')
		send_char(pid, av[2][i++]);
	send_char(pid, '\0'); 
	return (0);
}
