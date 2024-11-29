/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:31:20 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/29 18:10:33 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_getcolor(int start, int end, double prog)
{
	if (start == end)
		return (start);
	return (((int)(((start >> 16) & 0xFF) + prog * (((end >> 16) & 0xFF)
					- ((start >> 16) & 0xFF))) << 16) | ((int)(((start >> 8) & 0xFF)
				+ prog * (((end >> 8) & 0xFF)
					- ((start >> 8) & 0xFF))) << 8) | (int)((start & 0xFF)
			+ prog * ((end & 0xFF) - (start & 0xFF))));
}

void	ft_drawline(t_coords p1, t_coords p2, t_inst inst, t_trans trans)
{
	int		xlen;
	int		ylen;
	int		i;
	double	slope;

	xlen = ft_abs(p2.x - p1.x);
	ylen = ft_abs(p2.y - p1.y);
	i = -1;
	if (xlen > ylen)
	{
		slope = (double)(p2.y - p1.y) / (p2.x - p1.x);
		while (++i, i <= xlen)
		{
			mlx_pixel_put(inst.mlx, inst.mlx_win, p1.x + i + trans.xt, p1.y
				+ slope * i + trans.yt, ft_getcolor(p1.color, p2.color,
					(double)i / xlen));
		}
	}
	else
	{
		slope = (double)(p2.x - p1.x) / (p2.y - p1.y);
		while (++i, i <= ylen)
		{
			if (p2.y - p1.y < 0)
				mlx_pixel_put(inst.mlx, inst.mlx_win, p1.x + slope * (-i)
					+ trans.xt, p1.y - i + trans.yt, ft_getcolor(p1.color,
						p2.color, (double)i / ylen));
			else
				mlx_pixel_put(inst.mlx, inst.mlx_win, p1.x + slope * i
					+ trans.xt, p1.y + i + trans.yt, ft_getcolor(p1.color,
						p2.color, (double)i / ylen));
		}
	}
}

void	ft_drawpoints(t_list *coordsmap, t_inst inst, int color)
{
	int	x;
	int	y;

	x = -1;
	while (++x, coordsmap)
	{
		y = -1;
		while (++y, y < ((t_coordslst *)(coordsmap->content))->length)
			mlx_pixel_put(inst.mlx, inst.mlx_win,
				((t_coordslst *)(coordsmap->content))->coords[y].x,
				((t_coordslst *)(coordsmap->content))->coords[y].y, color);
		coordsmap = coordsmap->next;
	}
}

void	ft_drawlinks(t_list *coordsmap, t_inst inst, t_trans trans)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = -1;
	while (coordsmap)
	{
		i++;
		y = -1;
		while (++y, y < ((t_coordslst *)(coordsmap->content))->length)
		{
			if (y < ((t_coordslst *)(coordsmap->content))->length - 1
				&& coordsmap->next)
			{
				ft_drawline(((t_coordslst *)(coordsmap->content))->coords[y],
					((t_coordslst *)(coordsmap->content))->coords[y + 1], inst, trans);
				/*ft_drawline(((t_coordslst *)(coordsmap->content))->coords[y],
					((t_coordslst *)(coordsmap->next->content))->coords[y + 1],
					inst, trans);*/
			}
			if (y > 0 && coordsmap->next)
				ft_drawline(((t_coordslst *)(coordsmap->content))->coords[y],
					((t_coordslst *)(coordsmap->next->content))->coords[y],
					inst, trans);
		}
		coordsmap = coordsmap->next;
		x++;
	}
}
