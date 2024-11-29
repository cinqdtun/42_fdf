/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:26:42 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 20:25:27 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	char	*ptr;
	int		i;

	if (!s1 || !s2)
		return (0);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	ptr = malloc(total_size + 1);
	i = 0;
	if (!ptr)
		return (0);
	while (*s1)
	{
		ptr[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ptr[i] = *s2;
		s2++;
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
	struct			test_case
	{
		const char	*s1;
		const char	*s2;
		const char	*expected;
	};

	struct test_case	test_cases[] = {{"Hello, ", "world!", "Hello, world!"},
			{"", "world!", "world!"}, {"Hello, ", "", "Hello, "}, {"", "", ""},
			{"123", "456", "123456"}, {"foo", "bar", "foobar"}, {NULL, NULL,
			NULL}};

	for (int i = 0; test_cases[i].s1 != NULL; i++)
	{
		char			*result = ft_strjoin(test_cases[i].s1,
							test_cases[i].s2);
		printf("Test case %d: \"%s\" + \"%s\"\n", i + 1, test_cases[i].s1,
			test_cases[i].s2);
		printf("Expected: \"%s\"\n", test_cases[i].expected);
		printf("ft_strjoin: \"%s\"\n", result);
		printf("Match: %s\n\n", (result && strcmp(result,
					test_cases[i].expected) == 0) ? "Yes" : "No");
		free(result);
	}

	return (0);
}*/