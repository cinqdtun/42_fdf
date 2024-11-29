/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 09:54:16 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 22:34:27 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_pattern(const char *start, const char *pattern)
{
	int	i;

	i = 0;
	while (pattern[i])
	{
		if (pattern[i] != start[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		i;
	size_t	len_p;

	if (!little[0])
		return ((char *)big);
	if (len < 1)
		return (0);
	i = 0;
	len_p = ft_strlen(little);
	while (big[i] && (size_t)i < len - len_p + 1 && len > 0)
	{
		if (check_pattern(big + i, little))
			return ((char *)big + i);
		i++;
	}
	return (0);
}

/*#include <stdio.h>

int	main(void)
{
	// char pattern[] = "ea";
	char string1[30] = "aaabcabcd";
	char pattern1[] = "cd";
	char *first_occ;

	// char string[] = "In the heart of a sprawling, ancient forest,"
	//				"where the towering trees reached so high ";
	first_occ = ft_strnstr(&string1[0], &pattern1[0], 8);
	printf("\"%s\"\n", first_occ);
	return (1);
}*/