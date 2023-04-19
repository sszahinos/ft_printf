/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:54:09 by sersanch          #+#    #+#             */
/*   Updated: 2023/04/19 11:23:48 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long long int	lng_ptr;
	int						printed;
	int						aux;

	lng_ptr = (unsigned long long int)ptr;
	printed = ft_putstr("0x");
	if (printed == -1)
		return (-1);
	aux = ft_puthexa_ptr(lng_ptr, 0);
	if (aux == -1)
		return (-1);
	printed += aux;
	return (printed);
}
