/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:50:08 by sersanch          #+#    #+#             */
/*   Updated: 2022/11/18 17:28:17 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_puthexa(int num, char flag)
{
	int	temp;
	int	printed;

	printed = 0;
	temp = num % 16;
	while (temp >= 16)
	{
		
	}
	iddf (temp < 16)
	{
		printed = ft_putchar(UPPER_HEXA[temp]);
		if (printed == -1)
			return (-1);
	}
}
