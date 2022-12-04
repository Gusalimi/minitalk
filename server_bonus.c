/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:37:12 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/04 16:39:07 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"
#include <stdio.h>

void	callback(int signum, siginfo_t *siginfo, void *context)
{
	static char	c;
	static int	i;

	(void)context;
	c <<= 1;
	if (signum == SIGUSR1)
		c++;
	if (i == 7)
	{
		if (c == 0)
			kill(siginfo->si_pid, SIGUSR1);
		write(1, &c, 1);
		c = 0;
		i = -1;
	}
	i++;
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = callback;
	action.sa_flags = SA_SIGINFO;
	ft_printf("Server started, PID : %d\n", getpid());
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}
