/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:48:12 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/31 14:23:55 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calc_unsigned_len(unsigned long long n, int base)
{
	int	c;

	c = 0;
	if (n >= (unsigned long long)base)
	{
		c += ft_calc_unsigned_len(n / base, base);
		c += ft_calc_unsigned_len(n % base, base);
	}
	else
		c += 1;
	return (c);
}

static void	ft_print_unsigned_hex(unsigned long long n, char *set)
{
	if (n > 15)
	{
		ft_print_unsigned_hex(n / 16, set);
		ft_print_unsigned_hex(n % 16, set);
	}
	else
		ft_putchar_fd(set[n], 1);
}

int	ft_print_unsigned_hex_c(unsigned long long n, char *set)
{
	ft_print_unsigned_hex(n, set);
	return (ft_calc_unsigned_len(n, 16));
}
