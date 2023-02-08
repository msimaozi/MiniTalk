/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msimaozi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 10:20:02 by msimaozi          #+#    #+#             */
/*   Updated: 2023/02/08 10:20:13 by msimaozi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

void	send_kill(int pid, char *str)
{
	int		x;
	int		y;

	y = 0;
	while (str[y] != '\0')
	{
		x = 7;
		while (x >= 0)
		{
			if (str[y] >> x & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			x--;
		}
		y++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_kill(pid, argv[2]);
		send_kill(pid, "\n");
	}
	else
		ft_putstr_fd("Erro\n", 1);
	return (0);
}
