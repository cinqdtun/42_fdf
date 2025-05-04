/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:31:10 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 16:24:55 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dprintf.h"
#include <limits.h>
#include <stdio.h>

int	ft_dprintf(int fd, const char *str, ...)
{
	va_list	args;
	int		i;
	int		c;
	int		res;

	va_start(args, str);
	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			res = print_conversion(fd, args, str[i + 1]);
			if (res < 0)
				return (-1);
			c += res;
			i += 2;
			continue ;
		}
		write(fd, &str[i], 1);
		c++;
		i++;
	}
	va_end(args);
	return (c);
}
