/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:54:09 by sersanch          #+#    #+#             */
/*   Updated: 2022/11/22 18:41:27 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_putptr(void *ptr)
{
	unsigned long long int	lng_ptr;
	int	printed;

	lng_ptr = (unsigned long long int)ptr;
	printed = ft_puthexa_ptr(lng_ptr, 0);
	return (printed);
}
