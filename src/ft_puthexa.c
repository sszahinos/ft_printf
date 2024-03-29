/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:26:06 by sersanch          #+#    #+#             */
/*   Updated: 2023/04/19 11:23:37 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_puthexa(unsigned int num, char flag, int printed)
{
	int	aux;

	if (num >= 16)
	{
		aux = ft_puthexa(num / 16, flag, printed);
		if (aux == -1)
			return (-1);
		printed += aux;
	}
	if (flag == 'x')
		aux = write(1, &LOWER_HEXA[num % 16], 1);
	else
		aux = write(1, &UPPER_HEXA[num % 16], 1);
	if (aux == -1)
		return (-1);
	printed += aux;
	return (printed);
}
