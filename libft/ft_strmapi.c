/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:17:43 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 22:17:50 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			size;
	char			*ptr;

	if (!s)
		return (0);
	i = 0;
	size = ft_strlen(s);
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	while (i < size)
	{
		ptr[i] = f(i, s[i]);
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

/*char	example_func(unsigned int i, char c)
{
	return (c + i);
}

char	to_upper(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	struct			test_case
	{
		const char	*input;
		char		(*func)(unsigned int, char);
		const char	*expected;
	};

	struct test_case	test_cases[] = {{"abc", example_func, "ace"}, {"hello",
			example_func, "hfnos"}, {"hello", to_upper, "HELLO"}, {"",
			example_func, ""}, {NULL, NULL, NULL}};

	for (int i = 0; test_cases[i].input != NULL; i++)
	{
		char			*result = ft_strmapi(test_cases[i].input,
							test_cases[i].func);
		printf("Test case %d: \"%s\"\n", i + 1, test_cases[i].input);
		printf("Expected: \"%s\"\n", test_cases[i].expected);
		printf("ft_strmapi: \"%s\"\n", result);
		printf("Match: %s\n\n", (result && strcmp(result,
					test_cases[i].expected) == 0) ? "Yes" : "No");
		free(result);
	}

	return (0);
}*/