/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:18:45 by sersanch          #+#    #+#             */
/*   Updated: 2023/04/19 11:23:43 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_digits(long long int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int	ft_pow(int base, int power)
{
	int	i;
	int	result;

	if (power == 0)
		return (1);
	i = 1;
	result = base;
	while (i++ < power)
		result *= base;
	return (result);
}

static int	ft_print_digits(long long int li)
{
	int	digits;
	int	printed;

	digits = ft_count_digits(li) - 1;
	printed = 0;
	while (0 < digits)
	{
		if (ft_putchar((char)((li / ft_pow(10, digits--) % 10) + '0')) == -1)
			return (-1);
		printed++;
	}
	if (ft_putchar((li % 10) + '0') == -1)
		return (-1);
	return (++printed);
}

int	ft_putnbr(long long int n, int is_uint)
{
	long long int	li;
	int				printed;
	int				aux;

	if (n == -2147483648 && !is_uint)
		return (ft_putstr("-2147483648"));
	printed = 0;
	aux = 0;
	li = n;
	if (li < 0)
	{
		if (!is_uint)
		{
			printed = ft_putchar('-');
			if (printed == -1)
				return (-1);
		}
		li *= -1;
	}
	aux = ft_print_digits(li);
	if (aux == -1)
		return (-1);
	printed += aux;
	return (printed);
}
