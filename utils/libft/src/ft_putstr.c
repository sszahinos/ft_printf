/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:07:10 by sersanch          #+#    #+#             */
/*   Updated: 2022/11/18 11:54:10 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

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
