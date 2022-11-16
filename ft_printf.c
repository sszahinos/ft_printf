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

static void ft_select_print(char *str, int index, va_list args)
{
	//const char *flags = "cspdiuxX%%";
	int	printed;

	printed = 0;
	if (str[index + 1] == 'c')
		printed = ft_putchar(va_arg(args, char));
	else if (str[index + 1] == 's')
		printed = ft_putstr(va_arg(args, char *));
	else if (str[index + 1] == 'p')
		printed = ft_putptr(va_arg(args, char *));
	else if (str[index + 1] == 'd' || str[index + 1] == 'i')
		printed = ft_putnbr(va_arg(args, int));
	/*else if (str[index + 1] == 'i')
		printed = ft_putnbr((char *)arg, &printed);*/
	else if (str[index + 1] == 'u') // unsigned dec?
		return (¿¿¿???);
	else if (str[index + 1] == 'x')
		printed = ft_put_lower_hex((char *)arg, &printed);
	else if (str[index + 1] == 'X')
		printed = ft_put_upper_hex((char *)arg, &printed);
	else if (str[index + 1] == '%')
		printed = ft_putchar('%', &printed);
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

	printed = 0;
	va_start(args, count);
	while (str[i])
	{
		//flag = ft_get_flag(str, i); //busca lo que hay a la derecha si existe. si es una flag, la devuelve, si no, otra cosa (null)?
		printed += ft_select_print(str, i, args);
		i++;
	}
	va_end(args);
	return (printed);
}