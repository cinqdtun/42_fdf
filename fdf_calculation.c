/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_calculation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 15:02:02 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/29 17:31:06 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_getpointsproj(t_list *map, double rad, t_multi multi)
{
	int			x;
	int			y;
	t_coords	coords;
	t_coords	*coords_list;
	t_list		*list;
	int			len;

	x = -1;
	len = ft_lstsize(map);
	list = 0;
	while (++x, map)
	{
		coords_list = malloc(sizeof(t_coords)
				* ((t_zline *)map->content)->length);
		y = -1;
		while (++y, y < ((t_zline *)map->content)->length)
		{
			coords.x = ((x * multi.xm * cos(rad) + (len - y - 1) * multi.ym
						* cos(rad + 2) + ((t_zline *)(map->content))->zline[y].z
						* multi.zm * cos(rad - 2)));
			coords.y = ((x * multi.xm * sin(rad) + (len - y - 1) * multi.ym
						* sin(rad + 2) + ((t_zline *)(map->content))->zline[y].z
						* multi.zm * sin(rad - 2)));
			
			coords.color = ((t_zline *)(map->content))->zline[y].color;
			coords_list[y] = coords;
		}
		ft_lstaddcoords(&list, ((t_zline *)map->content)->length, coords_list);
		map = map->next;
	}
	return (list);
}

int	ft_getamplitude(t_list *zmap)
{
	int i;
	int max;
	int min;

	max = INT_MIN;
	min = INT_MAX;
	while (zmap)
	{
		i = -1;
		while (++i, i < ((t_zline *)zmap->content)->length)
		{
			max = ft_max(((t_zline *)zmap->content)->zline[i].z, max);
			min = ft_min(((t_zline *)zmap->content)->zline[i].z, min);
		}
		zmap = zmap->next;
	}
	ft_printf("Max %d, min %d amp %d", max, min, ft_abs(max) + ft_abs(min));
	return (ft_abs(max) + ft_abs(min));
}
