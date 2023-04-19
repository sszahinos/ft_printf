/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:07:10 by sersanch          #+#    #+#             */
/*   Updated: 2023/04/19 11:23:52 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
