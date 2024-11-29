/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:21:28 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 22:20:45 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			len_s;
	size_t			len_d;
	unsigned int	i;

	len_s = ft_strlen(src);
	if (!dst && !size)
		return (0);
	len_d = ft_strlen(dst);
	i = 0;
	if (size < len_d)
		return (len_s + size);
	while (len_d + (size_t)i + 1 < size && src[i])
	{
		dst[len_d + (size_t)i] = src[i];
		i++;
	}
	dst[len_d + (size_t)i] = '\0';
	return (len_d + len_s);
}
/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*dst;
	char	*src;
	size_t	result;
	int		i;

	dst = malloc(15);
	memset(dst, 0, 15);
	src = "lorem ipsum dolor sit amet";
	i = 0;
	(void)i;
	(void)src;
	printf("Before:                 || After:\n");
	printf("dst   | src   | size    || dst      | return\n");
	printf("------------------------||--------------------\n");
	ft_memset(dst, 'r', 15);
	// result = ft_strlcat(dst, src, 5);
	result = strlcat(dst, "lorem ipsum dolor sit amet", 5);
	printf("dst\\0 | src\\0 | %d       || %s    | %ld\n", 5, dst, result);
	// Used test value from here :
	// https://stackoverflow.com/questions/33154740/
	// strlcat-is-dst-always-nul-terminated-what-are-size-and-the-returned-value
	while (i < 9)
	{
		strcpy(dst, "dst");
		result = ft_strlcat(dst, src, i);
		printf("dst\\0 | src\\0 | %d       || %s    | %ld\n", i, dst, result);
		i++;
	}
return (0);
}*/