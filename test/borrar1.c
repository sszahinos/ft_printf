int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	printed;

	printed = 0;
	while (s[printed])
	{
		if (ft_putchar(s[printed]) == -1)
			return (-1);
		printed++;
	}
	return (printed);
}

/*ft_puntbr*/
static int ft_count_digits(int n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static int ft_pow(int base, int power)
{
	int i;
	int result;

	if (power == 0)
		return (1);
	i = 1;
	result = base;
	while (i++ < power)
		result *= base;
	return (result);
}

int	ft_print_digits(long int li)
{
	int	digits;
	int	printed;

	digits = ft_count_digits(li) - 1;
	printed = 0;
	while (0 < digits)
	{
		if (ft_putchar_fd((char)((li / ft_pow(10, digits--) % 10) + '0')) == -1)
			return (-1);
		printed++;
	}
	if (ft_putchar_fd((li % 10) + '0') == -1)
		return (-1);
	return (++printed);
}

int	ft_putnbr(int n, int is_uint)
{
	long int	li;
	int			printed;
	int			aux;

	printed = 0;
	aux = 0;
	li = (long int)n;
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
	if (li == 0)
		aux = ft_putchar('0'); //se podria quitar??
	else
		aux = ft_print_digits(li);
	if (aux == -1)
		return (-1);
	printed += aux;
	return (printed);
}
/*END PUTNBR*/

