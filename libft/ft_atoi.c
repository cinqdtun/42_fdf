/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:21:22 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/22 13:51:11 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(const char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	ft_atoi(const char *nptr)
{
	int	val;
	int	i;
	int	sign;

	val = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		val *= 10;
		val += nptr[i] - '0';
		i++;
	}
	return (val * sign);
}

/*#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	const char *test_cases[] = {"42", "   -42", "4193 with words",
		"words and 987", "-91283472332", "+123", "0", "   +0", "   -0",
		"2147483647", "-2147483648", "   123abc456", 0};

	for (int i = 0; test_cases[i] != NULL; i++)
	{
		int result_ft = ft_atoi(test_cases[i]);
		int result_std = atoi(test_cases[i]);
		printf("Test case %d: \"%s\"\n", i + 1, test_cases[i]);
		printf("ft_atoi: %d\n", result_ft);
		printf("atoi: %d\n", result_std);
		printf("Match: %s\n\n", (result_ft == result_std) ? "Yes" : "No");
	}

	return (0);
}*/