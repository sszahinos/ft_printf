/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:02:03 by sersanch          #+#    #+#             */
/*   Updated: 2023/04/19 11:22:28 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_select_flag(char flag, va_list args)
{
	int	printed;

	printed = 0;
	if (flag == 'c')
		printed = ft_putchar((char)va_arg(args, int));
	else if (flag == 's')
		printed = ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
		printed = ft_putptr(va_arg(args, void *));
	else if (flag == 'd' || flag == 'i')
		printed = ft_putnbr((long long int)va_arg(args, int), 0);
	else if (flag == 'u')
		printed = ft_putnbr(va_arg(args, unsigned int), 1);
	else if (flag == 'x' || flag == 'X')
		printed = ft_puthexa(va_arg(args, int), flag, 0);
	else if (flag == '%')
		printed = ft_putchar(flag);
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		printed;
	int		printed_returned;

	printed = 0;
	va_start(args, str);
	i = 0;
	while (str[i])
	{
		printed_returned = 0;
		if (str[i] == '%')
			printed_returned = ft_select_flag(str[++i], args);
		else
			printed_returned = ft_putchar(str[i]);
		if (printed_returned == -1)
			return (-1);
		printed += printed_returned;
		i++;
	}
	va_end(args);
	return (printed);
}