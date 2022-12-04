/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:52:28 by gsaile            #+#    #+#             */
/*   Updated: 2022/11/08 12:54:31 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		counter;

	va_start(args, format);
	i = 0;
	counter = 0;
	while (format[i])
	{
		if (format[i] != '%')
			counter += ft_putchar_fd(format[i], 1);
		else
			parse_arg(&format[++i], args, &counter);
		i++;
	}
	va_end(args);
	return (counter);
}
