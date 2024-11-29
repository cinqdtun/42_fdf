/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 21:35:02 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/29 10:16:17 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_duplicates(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (++i, str[i])
	{
		j = i;
		while (++j, str[j])
		{
			if (str[i] == str[j])
				return (0);
		}
	}
	return (1);
}

int	is_base_valid(char *base, int size)
{
	int	i;

	i = -1;
	if (size < 2)
		return (0);
	while (++i, i < size)
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= ' ' || base[i] > '~')
			return (0);
	}
	return (check_duplicates(base));
}

int	get_char_index(char c, char *str)
{
	int	i;

	i = -1;
	while (++i, str[i])
	{
		if (str[i] == c)
			return (i);
	}
	return (-1);
}

int	calc_sign(char *str)
{
	int	neg;

	neg = 0;
	while (*str == '+' || *str == '-')
	{
		neg += *str == '-';
		str++;
	}
	if (neg % 2 == 1)
		return (-1);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	base_s;
	int	char_i;
	int	n;
	int	sign;

	if (!str || !base)
		return (0);
	base_s = ft_strlen(base);
	n = 0;
	if (!is_base_valid(base, base_s))
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = calc_sign(str);
	while (*str == '+' || *str == '-')
		str++;
	while (*(str++))
	{
		char_i = get_char_index(str[-1], base);
		if (char_i == -1)
			break ;
		n = n * base_s + char_i;
	}
	return (n * sign);
}
