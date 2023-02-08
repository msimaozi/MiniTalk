/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimaozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:20:23 by msimaozi          #+#    #+#             */
/*   Updated: 2023/02/08 10:20:26 by msimaozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	write_msg(int signal)
{
	static int	bit;
	static int	x;

	if (signal == SIGUSR1)
		x += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(x, 1);
		bit = 0;
		x = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		write(1, "Pid:", 4);
		ft_putnbr_fd(pid, 1);
		write(1, "\n", 1);
		while (1)
		{
			signal(SIGUSR1, write_msg);
			signal(SIGUSR2, write_msg);
			pause();
		}
	}
	else
		ft_putstr_fd("Error", 1);
	return (0);
}
