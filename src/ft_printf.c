/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 11:02:03 by sersanch          #+#    #+#             */
/*   Updated: 2022/11/18 17:28:10 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

static int	ft_select_flag(char flag, va_list args)
{
	int	printed;

	printed = 0;
	if (flag == 'c')
		printed = ft_putchar(va_arg(args, char));
	else if (flag == 's')
		printed = ft_putstr(va_arg(args, char *));
	else if (flag == 'p')
		printed = ft_putptr(va_arg(args, void *));
	else if (flag == 'd' || flag == 'i')
		printed = ft_putnbr(va_arg(args, int), 0);
	else if (flag == 'u') // unsigned int?
		printed = ft_putnbr(va_arg(args, unsigned int), 1);
	else if (flag == 'x' || flag == 'X')
		printed = ft_puthexa(va_arg(args, int), flag);
	/*else if (flag == 'X')
		printed = ft_put_upper_hex();*/
	else if (flag == '%')
		printed = ft_putchar(flag);
	return (printed);
}

static int	ft_count_args(char const *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i + 1])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", (int)str[i]))
			count++;
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		arg_count;
	int		i;
	int		printed;
	int		printed_returned;

	printed = 0;
	arg_count = ft_count_args(str);
	va_start(args, arg_count);
	i = 0;
	while (str[i])
	{
		printed_returned = ft_select_flag(str + i, args);
		if (printed_returned == -1)
			break ;
		printed += printed_returned;
		i++;
	}
	va_end(args);
	return (printed);
}
