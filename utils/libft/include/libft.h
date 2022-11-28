/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:53:30 by sersanch          #+#    #+#             */
/*   Updated: 2022/11/28 11:17:39 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define UPPER_HEXA "0123456789ABCDEF"
# define LOWER_HEXA "0123456789abcdef"

int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(long long int n, int is_uint);
int		ft_putptr(void *ptr);
int		ft_puthexa(unsigned int num, char flag, int printed);
int		ft_puthexa_ptr(unsigned long long int num, int printed);
char	*ft_strchr(const char *s, int c);

#endif
