/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:34:06 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/29 11:11:58 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	len;
	char	*ptr;

	i = 0;
	if (!s)
		return (0);
	len = ft_strlen(s);
	ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	while (s[i])
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	const char	*test_cases[] = {"Hello, world!", "",
			"A quick brown fox jumps over the lazy dog.", "1234567890",
			"!@#$%^&*()_+",
			"This is a longer string to test the strdup function.", NULL};
	char		*result_ft;
	char		*result_std;

	for (int i = 0; test_cases[i] != NULL; i++)
	{
		result_ft = ft_strdup(test_cases[i]);
		result_std = strdup(test_cases[i]);
		printf("Test case %d: \"%s\"\n", i + 1, test_cases[i]);
		printf("ft_strdup: \"%s\"\n", result_ft);
		printf("strdup: \"%s\"\n", result_std);
		printf("Match: %s\n\n", (strcmp(result_ft,
					result_std) == 0) ? "Yes" : "No");
		free(result_ft);
		free(result_std);
	}
	return (0);
}*/
