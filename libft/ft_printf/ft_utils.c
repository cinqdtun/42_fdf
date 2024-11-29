/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:41:01 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/31 14:23:39 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_conversion3(va_list args, char arg)
{
	if (arg == 'X')
		return (ft_print_unsigned_hex_c(va_arg(args, unsigned int),
				HEXA_SET_U));
	if (arg == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (-1);
}

static int	print_conversion2(va_list args, char arg)
{
	unsigned long long	ptr;

	if (arg == 'p')
	{
		ptr = va_arg(args, unsigned long long);
		if (!ptr)
		{
			ft_putstr_fd("(nil)", 1);
			return (5);
		}
		ft_putstr_fd("0x", 1);
		return (ft_print_unsigned_hex_c(ptr, HEXA_SET_L) + 2);
	}
	if (arg == 'd' || arg == 'i')
		return (ft_print_int_c(va_arg(args, int)));
	if (arg == 'u')
		return (ft_print_uint_c(va_arg(args, unsigned int)));
	if (arg == 'x')
	{
		return (ft_print_unsigned_hex_c(va_arg(args, unsigned int),
				HEXA_SET_L));
	}
	return (print_conversion3(args, arg));
}

int	print_conversion(va_list args, char arg)
{
	char	*str;

	if (arg == 'c')
	{
		ft_putchar_fd((char)va_arg(args, int), 1);
		return (1);
	}
	if (arg == 's')
	{
		str = va_arg(args, char *);
		if (!str)
		{
			ft_putstr_fd("(null)", 1);
			return (6);
		}
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	return (print_conversion2(args, arg));
}
