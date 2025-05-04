/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:04:09 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 14:23:17 by fdehan           ###   ########.fr       */
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
	ptr = ft_calloc(j + 1, sizeof(char));
	*start = i + j;
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
	ptr = (char **)ft_calloc(word_c + 1, sizeof(char *));
	if (!ptr)
		return (NULL);
	while (i < word_c)
	{
		ptr[i] = split_word(s, &start, c);
		i++;
	}
	return (ptr);
}
