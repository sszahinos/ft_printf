/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sersanch <sersanch@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 12:07:21 by sersanch          #+#    #+#             */
/*   Updated: 2023/04/19 11:29:43 by sersanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define UPPER_HEXA "0123456789ABCDEF"
# define LOWER_HEXA "0123456789abcdef"

int	ft_printf(const char *str, ...);
int ft_putchar(char c);
int ft_puthexa_ptr(unsigned long long int num, int printed);
int ft_puthexa(unsigned int num, char flag, int printed);
int ft_putnbr(long long int n, int is_uint);
int ft_putptr(void *ptr);
int ft_putstr(char *s);
char *ft_strchr(const char *s, int c);

#endif
