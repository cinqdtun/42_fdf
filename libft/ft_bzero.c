/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:43:19 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 21:14:22 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while ((size_t)i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "This is a test and must be diffrent after bzero";
	int len = 48;
	int i = 0;
	ft_bzero(str, 3);
	printf("Result after ft_bzero : ");
	while (i < len)
	{
		if (!str[i])
		{
			printf("\\0");
			i++;
			continue ;
		}
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
	char str1[] = "This is a test and must be diffrent after bzero";
	ft_bzero(str1, 0);
	i = 0;
	printf("Result after ft_bzero : ");
	while (i < len)
	{
		if (!str1[i])
		{
			printf("\\0");
			i++;
			continue ;
		}
		printf("%c", str1[i]);
		i++;
	}
	printf("\n");
	return (1);
}*/