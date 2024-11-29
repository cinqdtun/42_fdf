/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:11:43 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 20:26:08 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			sub_s;
	size_t			size;
	char			*ptr;

	if (!s)
		return (0);
	i = 0;
	size = ft_strlen(s);
	if (start > size)
		sub_s = 0;
	else if (size - (size_t)start > len)
		sub_s = len;
	else
		sub_s = size - (size_t)start;
	ptr = malloc(sub_s + 1);
	if (!ptr)
		return (0);
	while (i < sub_s)
	{
		ptr[i] = s[start + i];
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
	struct				test_case
	{
		const char		*input;
		unsigned int	start;
		size_t			len;
		const char		*expected;
	};

	struct test_case	test_cases[] = {{"Hello, world!", 7, 5, "world"},
			{"Hello, world!", 0, 5, "Hello"}, {"Hello, world!", 7, 0, ""},
			{"Hello, world!", 7, 50, "world!"}, {"Hello, world!", 50, 5, ""},
			{"", 0, 5, ""}, {NULL, 0, 0, NULL}};

	for (int i = 0; test_cases[i].input != NULL; i++)
	{
		char			*result = ft_substr(test_cases[i].input,
							test_cases[i].start, test_cases[i].len);
		printf("Test case %d: \"%s\", start = %u, len = %zu\n", i + 1,
			test_cases[i].input, test_cases[i].start, test_cases[i].len);
		printf("Expected: \"%s\"\n", test_cases[i].expected);
		printf("ft_substr: \"%s\"\n", result);
		printf("Match: %s\n\n", (result && strcmp(result,
					test_cases[i].expected) == 0) ? "Yes" : "No");
		free(result);
	}

	return (0);
}*/