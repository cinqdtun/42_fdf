/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:45:20 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/21 19:18:46 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t			len;
	unsigned int	i;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (src[i] && (size_t)i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "Hello I am a string !";
	char dest[100];
	char dest1[5];
	char dest2[30];
	printf("Size of src : %ld and dest contain : \"%s\"\n", ft_strlcpy(dest,
			str, 10), dest);
	printf("Size of src : %ld and dest contain : \"%s\"\n", ft_strlcpy(dest1,
			str, 5), dest1);
	printf("Size of src : %ld and dest contain : \"%s\"\n", ft_strlcpy(dest2,
			str, 0), dest2);
	return (1);
}*/