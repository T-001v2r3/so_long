/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:59:18 by gperfeit          #+#    #+#             */
/*   Updated: 2022/12/01 21:53:08 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_printstr("(null)"));
	while (s[i])
		write(1, &s[i++], 1);
	return (i);
}

int	ft_format(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += printchar(va_arg(args, int));
	else if (c == 's')
		len += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		len += ft_printptr(va_arg(args, unsigned long long));
	else if (c == 'i' || c == 'd')
		ft_put_nbr((va_arg(args, int)), &len, 0);
	else if (c == 'u')
		ft_put_nbr((va_arg(args, int)), &len, 1);
	else if (c == 'x' || c == 'X')
		ft_put_hex((va_arg(args, unsigned int)), &len, c);
	else if (c == '%')
		len += printchar('%');
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	va_end(args);
	while (*str)
	{
		if (*str == '%')
			len += ft_format(args, *(++str));
		else
			len += printchar(*str);
		str++;
	}
	va_end(args);
	return (len);
}
