#include <stdarg.h>

static const char *FLAGS = "cspdiuxX%%";

/*
int ft_check_flag(char c)
{
	const char *flags;
	int j;

	flags = "cspdiuxX\%";
	return (ft_strchr(flags, (int)c));
}

int	ft_check_params(const char *str, va_list args)
{
	int i;
	int	count;
	char *flags;

	flags = "cspdiuxX\%";
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_check_flag(str[i + 1]))
		{
			count++;
			i++;
		}
		i++;
	}
	//?¿? comparar count con num de args ?¿?
}
*/

static int ft_select_flag(char flag, va_list args)
{
	//const char *flags = "cspdiuxX%%";
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
		printed = ft_put_hex(va_arg(args, char *), flag);
	/*else if (flag == 'X')
		printed = ft_put_upper_hex();*/
	else if (flag == '%')
		printed = ft_putchar(flag);
	return (printed);
}

/*
char	ft_get_flag(char *str, int index)
{
	if (str[index + 1] && (ft_strchr(FLAGS, (int)str[index + 1])))
	{

	}
}*/

int ft_printf(const char *str, ...)
{
	int	printed;
	int	printed_returned;

	printed = 0;
	va_start(args, count);
	while (str[i])
	{
		//flag = ft_get_flag(str, i); //busca lo que hay a la derecha si existe. si es una flag, la devuelve, si no, otra cosa (null)?
		printed_returned = ft_select_flag(str + i, args);
		if (printed_returned == -1)
			break ;
		printed += printed_returned;
		i++;
	}
	va_end(args);
	return (printed);
}