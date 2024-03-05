/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gperfeit <gperfeit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:59:18 by gperfeit          #+#    #+#             */
/*   Updated: 2022/12/01 21:53:08 by gperfeit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

void	ft_put_hex(unsigned int value, int *l, int upper)
{
	if (value >= 16)
	{
		ft_put_hex(value / 16, l, upper);
		ft_put_hex(value % 16, l, upper);
	}
	else
	{
		if (value < 10)
			(*l) += printchar(value + '0');
		else if (upper == 'x')
			(*l) += printchar(value - 10 + 'a');
		else if (upper == 'X')
			(*l) += printchar(value - 10 + 'A');
	}
}

void	ft_put_nbr(unsigned int value, int *l, int unsig)
{
	if (!unsig && ((int)value) < 0)
	{
		write(1, "-", 1);
		(*l)++;
		value *= -1;
	}
	if (value >= 10)
	{
		ft_put_nbr(value / 10, l, unsig);
		ft_put_nbr(value % 10, l, unsig);
	}
	else
	{
		(*l) += printchar(value + '0');
	}
}

void	ft_put_ptr(unsigned long long p, int *l)
{
	if (p >= 16)
	{
		ft_put_ptr(p / 16, l);
		ft_put_ptr(p % 16, l);
	}
	else
	{
		if (p < 10)
			(*l) += printchar(p + '0');
		else
			(*l) += printchar(p - 10 + 'a');
	}
}

int	ft_printptr(unsigned long long p)
{
	int	size;

	if (!p)
		return (ft_printstr("(nil)"));
	size = 0;
	size += write(1, "0x", 2);
	ft_put_ptr(p, &size);
	return (size);
}
