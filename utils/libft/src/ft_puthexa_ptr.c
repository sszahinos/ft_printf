/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:48:07 by sersanch          #+#    #+#             */
/*   Updated: 2022/11/22 18:42:51 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <unistd.h>

int	ft_puthexa_ptr(unsigned long long int num, int printed)
{
	int	aux;

	if (num >= 16)
	{
		aux = ft_puthexa_ptr(num / 16, printed);
		if (aux == -1)
			return (-1);
		printed += aux;
	}
	aux = write(1, &LOWER_HEXA[num % 16], 1);
	if (aux == -1)
		return (-1);
	printed += aux;
	return (printed);
}
