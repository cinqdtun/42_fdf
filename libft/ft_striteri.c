/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:25:09 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 20:44:51 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;
	size_t			size;

	if (!s || !f)
		return ;
	i = 0;
	size = ft_strlen(s);
	while (i < size)
	{
		f(i, &s[i]);
		i++;
	}
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	example_func(unsigned int i, char *c)
{
	*c = *c + i;
}

void	to_upper(unsigned int i, char *c)
{
	(void)i;
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}

int	main(void)
{
	struct			test_case
	{
		char		input[50];
		void		(*func)(unsigned int, char *);
		const char	*expected;
	};

	struct test_case test_cases[] = {
		{"abc", example_func, "ace"},
		{"hello", example_func, "hfnos"},
		{"hello", to_upper, "HELLO"},
		{"", example_func, ""},
		{"", NULL, NULL}
	};

	for (int i = 0; test_cases[i].input[0] != '\0'
		|| test_cases[i].func != NULL; i++)
	{
		char		*input_copy = strdup(test_cases[i].input);
		ft_striteri(input_copy, test_cases[i].func);
		printf("Test case %d: \"%s\"\n", i + 1, test_cases[i].input);
		printf("Expected: \"%s\"\n", test_cases[i].expected);
		printf("ft_striteri: \"%s\"\n", input_copy);
		printf("Match: %s\n\n", (strcmp(input_copy,
					test_cases[i].expected) == 0) ? "Yes" : "No");
		free(input_copy);
	}

	return (0);
}*/
