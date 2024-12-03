/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_map_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:44:02 by fdehan            #+#    #+#             */
/*   Updated: 2024/12/03 18:27:13 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_ishexa(char *str, char *hexaset)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	i = 2;
	if (len < 3 || len > 10 || ft_strncmp("0x", str, 2))
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
	if ((colorsub && (ft_strlen(colorsub) < 2 || !ft_ishexa(colorsub + 1,
					ft_gethexaset(colorsub + 3)))) || !ft_is_valid_until(point,
			','))
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
	t_zline		*zline;
	t_pointz	*point;

	split = ft_parse_line(line);
	if (!split)
		return (NULL);
	i = -1;
	zline = malloc(sizeof(t_zline));
	if (!zline)
		return (ft_freearray(split), NULL);
	zline->zline = malloc(sizeof(t_pointz) * ft_splitlen(split));
	if (!(zline->zline))
		return (free(zline), ft_freearray(split), NULL);
	while (++i, split[i])
	{
		point = ft_parsepoint(split[i]);
		if (!point)
			return (ft_freearray(split), free(zline->zline), free(zline), NULL);
		zline->zline[i] = *point;
		free(point);
	}
	zline->length = i;
	return (ft_freearray(split), zline);
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
			return (ft_putendl_fd(INVALID_MAP, 2), free(line),
				ft_lstclear(&zmap, &ft_freedataparse), ft_freegnl(), NULL);
		if (ft_lstadd(&zmap, zline) == -1)
			return (ft_putendl_fd(PARSING_ADD_FAILED, 2), free(line),
				ft_lstclear(&zmap, &ft_freedataparse), ft_freegnl(),
				free(zline), NULL);
		free(line);
		line = get_next_line(fd);
	}
	return (zmap);
}
