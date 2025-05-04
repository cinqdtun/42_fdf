/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:41:01 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 14:45:21 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"

static int	print_conversion3(int fd, va_list args, char arg)
{
	if (arg == 'X')
		return (ft_print_unsigned_hex_c(fd, va_arg(args, unsigned int),
				HEXA_SET_U));
	if (arg == '%')
	{
		ft_putchar_fd('%', fd);
		return (1);
	}
	return (-1);
}

static int	print_conversion2(int fd, va_list args, char arg)
{
	unsigned long long	ptr;

	if (arg == 'p')
	{
		ptr = va_arg(args, unsigned long long);
		if (!ptr)
		{
			ft_putstr_fd("(nil)", fd);
			return (5);
		}
		ft_putstr_fd("0x", fd);
		return (ft_print_unsigned_hex_c(fd, ptr, HEXA_SET_L) + 2);
	}
	if (arg == 'd' || arg == 'i')
		return (ft_print_int_c(fd, va_arg(args, int)));
	if (arg == 'u')
		return (ft_print_uint_c(fd, va_arg(args, unsigned int)));
	if (arg == 'x')
	{
		return (ft_print_unsigned_hex_c(fd, va_arg(args, unsigned int),
				HEXA_SET_L));
	}
	return (print_conversion3(fd, args, arg));
}

int	print_conversion(int fd, va_list args, char arg)
{
	char	*str;

	if (arg == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), fd);
		return (1);
	}
	if (arg == 's')
	{
		str = va_arg(args, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", fd);
			return (6);
		}
		ft_putstr_fd(str, fd);
		return (ft_strlen(str));
	}
	return (print_conversion2(fd, args, arg));
}
