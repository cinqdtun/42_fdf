/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:58:42 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/22 14:56:19 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if (!c)
		return ((char *)s + len);
	while ((size_t)i < len)
	{
		if (s[len - (size_t)i - 1] == (char)c)
			return ((char *)s + len - (size_t)i - 1);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "This a test to find if my function work fine";
	printf("Last occurence \'o\' starting at : \"%s\"\n", ft_strrchr(str, 'o'));
	printf("Last occurence \'g\' starting at : \"%s\"\n", ft_strrchr(str, 'g'));
	printf("Last occurence \'\\0\' starting at : \"%s\"\n", ft_strrchr(str,
			'\0'));
	return (0);
}*/