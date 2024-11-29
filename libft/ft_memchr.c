/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 22:22:35 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/21 22:42:40 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int	i;

	i = 0;
	while ((size_t)i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	char	str[] = "This a test to find if my function work fine";

	printf("First occurence \'d\' starting at : \"%s\"\n",
		(char *)ft_memchr(str, 'd', 20));
	printf("First occurence \'g\' starting at : \"%s\"\n",
		(char *)ft_memchr(str, 'g', 40));
	printf("First occurence \'\\0\'starting at : \"%s\"\n",
		(char *)ft_memchr(str, '\0', 5));
	return (1);
}*/
