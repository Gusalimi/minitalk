/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 09:36:09 by gsaile            #+#    #+#             */
/*   Updated: 2022/12/04 16:47:54 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	ft_atoi(const char *str)
{
	unsigned int		result;
	int					sign;
	char				*tmp;

	result = 0;
	sign = 1;
	tmp = (char *)str;
	if (*tmp == '+')
		tmp++;
	else if (*tmp == '-')
	{
		sign = -1;
		tmp++;
	}
	while (*tmp)
	{
		result *= 10;
		result += *tmp - '0';
		tmp++;
	}
	return (result * sign);
}

int	mt_strlen(char *s)
{
	int	i;

	if (!s)
		return (1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	send_bits(unsigned char c, int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> 7) % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(150);
		i++;
		c <<= 1;
	}
}

int	main(int argc, char **argv)
{
	unsigned char	c;
	char			*s;
	int				i;
	int				j;
	int				len;

	if (argc != 3)
		return (ft_putstr_fd("Usage: ./client <pid> <text>\n", 2));
	s = argv[2];
	j = 0;
	len = mt_strlen(s);
	while (j < len)
	{
		i = 0;
		c = s[j++];
		send_bits(c, ft_atoi(argv[1]));
	}
	return (0);
}
