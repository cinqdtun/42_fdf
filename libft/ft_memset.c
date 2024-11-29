/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:32:01 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/22 14:28:05 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((size_t)i < n)
	{
		((char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stdio.h>

int	main(void)
{
	char str[] = "This is a test and must be diffrent after memset";
	printf("Result after ft_memset : %s\n", (char *)ft_memset(str, 'a', 3));
	char str1[] = "This is a test and must be diffrent after memset";
	printf("Result after ft_memset : %s\n", (char *)ft_memset(str1, '~', 0));
	return (1);
}*/