/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:22:02 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 22:20:26 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (!c)
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "This a test to find if my function work fine";
	printf("First occurence \'d\' starting at : \"%s\"\n", ft_strchr(str, 'd'));
	printf("First occurence \'g\' starting at : \"%s\"\n", ft_strchr(str, 'g'));
	printf("First occurence \'\\0\'starting at : \"%s\"\n", ft_strchr(str,
			'\0'));
	return (0);
}*/