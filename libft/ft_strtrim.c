/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:35:02 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 20:24:13 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	contains(char const c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	count_char(char const *s1, char const *set)
{
	int	i;
	int	c;
	int	len;

	i = 0;
	c = 0;
	len = ft_strlen(s1);
	while (s1[i])
	{
		if (contains(s1[i], set))
			c++;
		else
			break ;
		i++;
	}
	i = 0;
	while (i < len && c < len)
	{
		if (contains(s1[len - i - 1], set))
			c++;
		else
			break ;
		i++;
	}
	return (len - c);
}

static void	trim_string(char const *s1, char const *set, char *trim_str)
{
	int	start;
	int	end;
	int	i;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (contains(s1[start], set))
		start++;
	while (contains(s1[end - 1], set))
		end--;
	while (start + i < end)
	{
		trim_str[i] = s1[start + i];
		i++;
	}
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		size;
	char	*ptr;

	if (!s1 || !set)
		return (0);
	size = count_char(s1, set);
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	if (size > 0)
		trim_string(s1, set, ptr);
	ptr[size] = '\0';
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
		const char	*set;
		const char	*expected;
	};

	struct test_case test_cases[] = {
		{"  Hello, world!  ", " ", "Hello, world!"},
		{"--Hello, world!--", "-", "Hello, world!"},
		{"xxHello, world!xx", "x", "Hello, world!"},
		{"  \t\nHello, world!  \t\n", " \t\n", "Hello, world!"},
		{"Hello, world!", "", "Hello, world!"},
		{"", " ", ""},
		{"  ", " ", ""},
		{"lorem ipsum dolor sit amet", "tel", "orem ipsum dolor sit am"},
		{NULL, NULL, NULL}
	};

	for (int i = 0; test_cases[i].s1 != NULL; i++)
	{
		char			*result = ft_strtrim(test_cases[i].s1,
							test_cases[i].set);
		printf("Test case %d: \"%s\" with set \"%s\"\n", i + 1,
			test_cases[i].s1, test_cases[i].set);
		printf("Expected: \"%s\"\n", test_cases[i].expected);
		printf("ft_strtrim: \"%s\"\n", result);
		printf("Match: %s\n\n", (result && strcmp(result,
					test_cases[i].expected) == 0) ? "Yes" : "No");
		free(result);
	}

	return (0);
}*/