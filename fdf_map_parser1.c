/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parser1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 23:07:18 by fdehan            #+#    #+#             */
/*   Updated: 2024/12/03 16:01:38 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_is_int(char *str, size_t lim)
{
	if (str[0] == '-')
	{
		if (lim > ft_strlen(INT_MIN_C) || (lim == ft_strlen(INT_MIN_C)
				&& ft_strncmp(str, INT_MIN_C, lim) > 0))
			return (0);
	}
	else
	{
		if (lim > ft_strlen(INT_MAX_C) || (lim == ft_strlen(INT_MAX_C)
				&& ft_strncmp(str, INT_MAX_C, lim) > 0))
			return (0);
	}
	return (1);
}

int	ft_is_valid_until(char *str, int c)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] != c)
	{
		if ('0' > str[i] || str[i] > '9')
			return (0);
		i++;
		num = 1;
	}
	if (!ft_is_int(str, i))
		return (0);
	return (num);
}

char	**ft_parse_line(char *line)
{
	char	*linetemp;
	char	**split;

	linetemp = ft_strtrim(line, "\n");
	if (!linetemp)
		return (0);
	split = ft_split(linetemp, ' ');
	free(linetemp);
	return (split);
}

int	ft_contains(char *set, int c)
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

void	ft_freedataparse(void *data)
{
	t_zline	*line;

	line = (t_zline *)data;
	free(line->zline);
	free(line);
}
