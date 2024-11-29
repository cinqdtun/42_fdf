/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:44:02 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/29 17:33:48 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_free_data(void *data)
{
	t_zline	*line;

	line = (t_zline *)data;
	free(line->zline);
	free(line);
}

static int	ft_is_int(char *str)
{
	if (str[0] == '-')
	{
		if (ft_strlen(str) > ft_strlen(INT_MIN_C)
			|| (ft_strlen(str) == ft_strlen(INT_MIN_C) && ft_strcmp(str,
					INT_MIN_C) > 0))
			return (0);
	}
	else
	{
		if (ft_strlen(str) > ft_strlen(INT_MAX_C)
			|| (ft_strlen(str) == ft_strlen(INT_MAX_C) && ft_strcmp(str,
					INT_MAX_C) > 0))
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
	if (!ft_is_int(str))
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

int	ft_ishexa(char *str, char *hexaset)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 2;
	if (len < 3 || len > 10 || strncmp("0x", str, 2))
		return (0);
	while (str[i])
	{
		
		if (!ft_contains(hexaset, str[i]))
			return (0);
		i++;
	}
	return (1);
}

t_pointz	*ft_parsepoint(char *point)
{
	char		*colorsub;
	t_pointz	*spoint;

	spoint = malloc(sizeof(t_pointz));
	if (!spoint)
		return (NULL);
	colorsub = ft_strchr(point, ',');
	if ((colorsub && !ft_ishexa(colorsub + 1, ft_gethexaset(colorsub + 3))) /*|| !ft_is_valid_until(point, ',')*/)
		return (free(spoint), NULL);
	spoint->z = ft_atoi(point);
	spoint->color = 0x00FFFFFF;
	if (colorsub)
		spoint->color = ft_atoi_base(colorsub + 3, ft_gethexaset(colorsub + 3));
	return (spoint);
}

t_zline	*ft_parse_zline(char *line)
{
	char		**split;
	int			i;
	t_zline		*zmapline;
	t_pointz	*point;

	split = ft_parse_line(line);
	if (!split)
		return (NULL);
	i = -1;
	zmapline = malloc(sizeof(t_zline));
	if (!zmapline)
		return (ft_free_array(split), NULL);
	zmapline->zline = malloc(sizeof(t_pointz) * ft_splitlen(split));
	if (!(zmapline->zline))
		return (free(zmapline), ft_free_array(split), NULL);
	while (++i, split[i])
	{
		point = ft_parsepoint(split[i]);
		if (!point)
			return (ft_free_array(split), free(zmapline->zline), free(zmapline),
				NULL);
		zmapline->zline[i] = *point;
		free(point);
	}
	ft_free_array(split);
	zmapline->length = i;
	return (zmapline);
}

t_list	*ft_parse_map(char *path)
{
	int		fd;
	char	*line;
	t_zline	*zline;
	t_list	*zmap;

	zmap = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	while (line)
	{
		zline = ft_parse_zline(line);
		if (!zline)
			return (ft_lstclear(&zmap, &ft_free_data), NULL);
		if (ft_lstadd(&zmap, zline) == -1)
			return (ft_lstclear(&zmap, &ft_free_data), free(zline), NULL);
		free(line);
		line = get_next_line(fd);
	}
	return (zmap);
}
