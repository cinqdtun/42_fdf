/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:04:09 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/29 14:39:25 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	i;
	int	j;
	int	can_c;

	i = 0;
	j = 0;
	can_c = 0;
	while (s[i])
	{
		if (s[i] == c && can_c)
		{
			can_c = 0;
			j++;
		}
		else if (s[i] != c)
			can_c = 1;
		i++;
	}
	return (j + can_c);
}

static char	*split_word(char const *str, int *start, char c)
{
	int		i;
	int		j;
	char	*ptr;

	i = *start;
	j = 0;
	while (str[i] == c)
		i++;
	while (str[i + j] != c && str[i + j])
		j++;
	ptr = malloc(j + 1);
	*start = i + j;
	ptr[j] = '\0';
	while (--j >= 0)
		ptr[j] = str[i + j];
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_c;
	int		start;
	char	**ptr;

	if (!s)
		return (0);
	i = 0;
	word_c = count_words(s, c);
	start = 0;
	ptr = (char **)malloc((word_c + 1) * sizeof(char *));
	if (!ptr)
		return (0);
	while (i < word_c)
	{
		ptr[i] = split_word(s, &start, c);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	print_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		printf("\"%s\"", split[i]);
		if (split[i + 1])
			printf(", ");
		i++;
	}
	printf("\n");
}

int	main(void)
{
	struct			test_case
	{
		const char	*s;
		char		c;
		const char *expected[10]; // Adjust size as needed
	};

	struct test_case	test_cases[] = {{"Hello world this is a test", ' ',
			{"Hello", "world", "this", "is", "a", "test", NULL}},
			{"Hello,world,this,is,a,test", ',', {"Hello", "world", "this", "is",
			"a", "test", NULL}}, {"Hello world this is a test", 'x',
			{"Hello world this is a test", NULL}}, {"", ' ', {NULL}}, {"   ",
			' ', {NULL}}, {"Hello world  this  is  a  test", ' ', {"Hello",
			"world", "this", "is", "a", "test", NULL}}, {NULL, 0, {NULL}}};

	for (int i = 0; test_cases[i].s != NULL; i++)
	{
		char		**result = ft_split(test_cases[i].s, test_cases[i].c);
		printf("Test case %d: \"%s\" with delimiter '%c'\n", i + 1,
			test_cases[i].s, test_cases[i].c);
		printf("Expected: ");
		for (int j = 0; test_cases[i].expected[j] != NULL; j++)
		{
			printf("\"%s\"", test_cases[i].expected[j]);
			if (test_cases[i].expected[j + 1])
				printf(", ");
		}
		printf("\n");
		printf("ft_split: ");
		print_split(result);
		int			match = 1;
		for (int j = 0; test_cases[i].expected[j] != NULL; j++)
		{
			if (strcmp(result[j], test_cases[i].expected[j]) != 0)
			{
				match = 0;
				break ;
			}
		}
		printf("Match: %s\n\n", match ? "Yes" : "No");
		free_split(result);
	}

	return (0);
}*/