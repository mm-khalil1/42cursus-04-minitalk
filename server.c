/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhalil <mkhalil@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:34:29 by mkhalil           #+#    #+#             */
/*   Updated: 2022/12/29 13:14:48 by mkhalil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_message(int signum)
{
	static int	bit;
	static int	c;

	if (signum == SIGUSR1)
		c |= (0x80 >> bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	int	pid;

	(void)av;
	if (ac != 1)
	{
		ft_putstr_fd("server: invalid arguments!\n", 1);
		return (0);
	}
	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
	{
		signal(SIGUSR1, handle_message);
		signal(SIGUSR2, handle_message);
		pause ();
	}
	return (0);
}
