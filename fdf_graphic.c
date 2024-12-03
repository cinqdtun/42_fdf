/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_graphic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 14:31:20 by fdehan            #+#    #+#             */
/*   Updated: 2024/12/03 10:48:31 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawpixelimg(t_windata *windata, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || windata->width <= x || y < 0 || windata->height <= y)
		return ;
	dst = windata->addr + (y * windata->line_length + x
			* (windata->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

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

void	ft_drawline(t_coords p1, t_coords p2, t_trans trans, t_windata *windata)
{
	int		xlen;
	int		ylen;
	int		i;
	double	slope;

	xlen = ft_abs(p2.x - p1.x);
	ylen = ft_abs(p2.y - p1.y);
	i = -1;
	if (xlen > ylen)
		slope = (double)(p2.y - p1.y) / (p2.x - p1.x);
	else
		slope = (double)(p2.x - p1.x) / (p2.y - p1.y);
	while (++i, i <= ft_max(xlen, ylen))
	{
		if (xlen > ylen)
			ft_drawpixelimg(windata, p1.x + i + trans.xt, p1.y + slope * i
				+ trans.yt, ft_getcolor(p1.color, p2.color, (double)i / xlen));
		else if (p2.y - p1.y < 0)
			ft_drawpixelimg(windata, p1.x + slope * (-i) + trans.xt, p1.y - i
				+ trans.yt, ft_getcolor(p1.color, p2.color, (double)i / ylen));
		else
			ft_drawpixelimg(windata, p1.x + slope * i + trans.xt, p1.y + i
				+ trans.yt, ft_getcolor(p1.color, p2.color, (double)i / ylen));
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

void	ft_drawlinks(t_list *coordsmap, t_windata *data, t_trans trans)
{
	int	y;

	while (coordsmap)
	{
		y = -1;
		while (++y, y < ((t_coordslst *)(coordsmap->content))->length)
		{
			if (y < ((t_coordslst *)(coordsmap->content))->length - 1
				&& coordsmap->next)
			{
				ft_drawline(((t_coordslst *)(coordsmap->content))->coords[y],
					((t_coordslst *)(coordsmap->content))->coords[y + 1], trans,
					data);
			}
			if (y > 0 && coordsmap->next)
				ft_drawline(((t_coordslst *)(coordsmap->content))->coords[y],
					((t_coordslst *)(coordsmap->next->content))->coords[y],
					trans, data);
		}
		coordsmap = coordsmap->next;
	}
}
