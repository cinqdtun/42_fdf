/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 15:45:48 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 22:32:24 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!dest && !src)
		return (0);
	if (dest > src)
	{
		while ((size_t)++i <= n)
			((char *)dest)[n - i] = ((char *)src)[n - i];
	}
	else
	{
		while ((size_t)++i <= n)
			((char *)dest)[i - 1] = ((char *)src)[i - 1];
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char str[] = "Hey test";
	printf("Text after memcpy : %s\n", (char *)ft_memmove(str + 1, str, 3));
	char str1[] = "Hey test";
	printf("Text after memcpy(OG) : %s\n", (char *)memmove(str1 + 1, str1, 3));
	char str2[] = "Hey test";
	printf("Text after memcpy : %s\n", (char *)ft_memmove(str2, str2 + 1, 4));
	char str3[] = "Hey test";
	printf("Text after memcpy(OG) : %s\n", (char *)memmove(str3, str3 + 1, 4));
	return (1);
}*/