/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:30:46 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/31 14:23:52 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_calc_int_len(int n, int base)
{
	int	c;

	c = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		c++;
	}
	if (n >= base)
	{
		c += ft_calc_int_len(n / base, base);
		c += ft_calc_int_len(n % base, base);
	}
	else
		c += 1;
	return (c);
}

static int	ft_calc_uint_len(unsigned int n, int base)
{
	int	c;

	c = 0;
	if (n >= (unsigned int)base)
	{
		c += ft_calc_uint_len(n / base, base);
		c += ft_calc_uint_len(n % base, base);
	}
	else
		c += 1;
	return (c);
}

static void	ft_print_uint(unsigned int n)
{
	if (n >= 10)
	{
		ft_print_uint(n / 10);
		ft_print_uint(n % 10);
	}
	else
		ft_putchar_fd(n + '0', 1);
}

int	ft_print_int_c(int n)
{
	ft_putnbr_fd(n, 1);
	return (ft_calc_int_len(n, 10));
}

int	ft_print_uint_c(int n)
{
	ft_print_uint(n);
	return (ft_calc_uint_len(n, 10));
}
