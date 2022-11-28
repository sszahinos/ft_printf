/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:07:10 by sersanch          #+#    #+#             */
/*   Updated: 2022/11/28 11:30:02 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putstr(char *s)
{
	int	printed;
	
	if (!s)
		return (ft_putstr("(null)"));
	printed = 0;
	while (s[printed])
	{
		if (ft_putchar(s[printed]) == -1)
			return (-1);
		printed++;
	}
	return (printed);
}
