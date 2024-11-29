/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:45:33 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 18:59:55 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	if (n < 1)
		return (0);
	while ((size_t)i < n - 1)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			break ;
		}
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

/*#include <stdio.h>

int	main(void)
{
	printf("Diffrence beetween is %d\n", ft_memcmp("test", "test", 5));
	printf("Diffrence beetween is %d\n", ft_memcmp("testee", "test", 6));
	printf("Diffrence beetween is %d\n", ft_memcmp("", "", 2));
	printf("Diffrence beetween is %d\n", ft_memcmp("Hey", "Hello", 2));
	printf("Diffrence beetween is %d\n", ft_memcmp("Hello", "Hey", 3));
	return (1);
}*/