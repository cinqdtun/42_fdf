/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:53:07 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 20:22:14 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_size(int n)
{
	int	c;

	c = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		c++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	int		size;
	char	*ptr;

	size = count_size(n);
	ptr = malloc(size + 1);
	if (!ptr)
		return (0);
	ft_bzero(ptr, size + 1);
	if (n == -2147483648)
	{
		ptr[--size] = '8';
		n /= 10;
	}
	if (n < 0)
	{
		ptr[0] = '-';
		n = -n;
	}
	while (size--, size >= 0 && ptr[size] != '-')
	{
		ptr[size] = n % 10 + '0';
		n /= 10;
	}
	return (ptr);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	struct			test_case
	{
		int			input;
		const char	*expected;
	};

	struct test_case	test_cases[] = {{0, "0"}, {1, "1"}, {-1, "-1"}, {123,
			"123"}, {-123, "-123"}, {2147483647, "2147483647"}, {-2147483648,
			"-2147483648"}, {42, "42"}, {-42, "-42"}, {10, "10"}, {0, NULL}};

	for (int i = 0; test_cases[i].expected != NULL; i++)
	{
		char		*result = ft_itoa(test_cases[i].input);
		printf("Test case %d: %d\n", i + 1, test_cases[i].input);
		printf("Expected: \"%s\"\n", test_cases[i].expected);
		printf("ft_itoa: \"%s\"\n", result);
		printf("Match: %s\n\n", (result && strcmp(result,
					test_cases[i].expected) == 0) ? "Yes" : "No");
		free(result);
	}

	return (0);
}*/