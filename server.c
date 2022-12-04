/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:37:12 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/04 16:44:25 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	callback(int signum)
{
	static char	c;
	static int	i;

	c <<= 1;
	if (signum == SIGUSR1)
		c++;
	if (i == 7)
	{
		write(1, &c, 1);
		c = 0;
		i = -1;
	}
	i++;
}

int	main(void)
{
	ft_printf("Server started, PID : %d\n", getpid());
	signal(SIGUSR1, callback);
	signal(SIGUSR2, callback);
	while (1)
		pause();
	return (0);
}
