/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 21:59:06 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/23 13:01:26 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n < 1)
		return (0);
	while ((s1[i] || s2[i]) && (size_t)i < n - 1)
	{
		if (s1[i] != s2[i])
		{
			break ;
		}
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("Diffrence beetween is %d\n", ft_strncmp("test", "test", 5));
	printf("Diffrence beetween is %d\n", ft_strncmp("testee", "test", 6));
	printf("Diffrence beetween is %d\n", ft_strncmp("", "", 2));
	printf("Diffrence beetween is %d\n", ft_strncmp("Hey", "Hello", 2));
	printf("Diffrence beetween is %d\n", ft_strncmp("Hey", "Hello", 3));
	return (1);
}*/