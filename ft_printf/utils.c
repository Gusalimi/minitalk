/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:38:32 by gsaile            #+#    #+#             */
/*   Updated: 2022/11/08 12:42:02 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	if (fd < 0)
		return (0);
	write(fd, &c, 1);
	return (1);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	value;
	int				i;

	i = 0;
	value = ft_strlen(base);
	if (!base)
		return (0);
	if (nbr >= value)
	{
		i += ft_putnbr_base(nbr / value, base);
		ft_putnbr_base(nbr % value, base);
	}
	else
		ft_putchar_fd(base[nbr], 1);
	i++;
	return (i);
}

int	ft_putlnbr_base(unsigned long long int nbr, char *base)
{
	unsigned int	value;
	int				i;

	i = 0;
	value = ft_strlen(base);
	if (!base)
		return (0);
	if (nbr >= value)
	{
		i += ft_putlnbr_base(nbr / value, base);
		ft_putlnbr_base(nbr % value, base);
	}
	else
		ft_putchar_fd(base[nbr], 1);
	i++;
	return (i);
}

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (fd < 0)
		return (0);
	if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-', fd);
	}
	else
		nb = n;
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
	return (ft_get_len(n));
}

int	ft_putunbr_fd(unsigned int n, int fd)
{
	if (fd < 0)
		return (0);
	if (n > 9)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
	return (ft_get_ulen(n));
}
