/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsaile <gsaile@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:00:44 by gsaile            #+#    #+#             */
/*   Updated: 2022/11/08 12:53:45 by gsaile           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_base(unsigned int nbr, char *base);
int		ft_putlnbr_base(unsigned long long int nbr, char *base);
int		ft_putnbr_fd(int n, int fd);
int		ft_putunbr_fd(unsigned int n, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_get_len(int n);
int		ft_get_ulen(unsigned int n);
void	parse_arg(const char *format, va_list args, int *counter);
size_t	ft_strlen(const char *s);

#endif
