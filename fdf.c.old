/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:19:02 by fdehan            #+#    #+#             */
/*   Updated: 2024/12/03 14:57:11 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_freeproj(t_windata *windata)
{
	mlx_destroy_display(windata->mlx);
	free(windata->mlx);
}

static void	ft_initwinandimg(t_windata *windata, t_properties prop,
		char *winname)
{
	windata->mlx_win = mlx_new_window(windata->mlx, prop.winw, prop.winh,
			winname);
	windata->img = mlx_new_image(windata->mlx, prop.winw, prop.winh);
	windata->width = prop.winw;
	windata->height = prop.winh;
	windata->addr = mlx_get_data_addr(windata->img, &windata->bits_per_pixel,
			&windata->line_length, &windata->endian);
}

static t_properties	ft_getprojproperties(int mapw, int maph, t_windata windata)
{
	int				screenw;
	int				screenh;
	t_properties	prop;

	mlx_get_screen_size(windata.mlx, &screenw, &screenh);
	prop.projh = sqrt(mapw * mapw / 2);
	prop.projw = sqrt(maph * maph / 2);
	prop.scale = ft_min((double)screenh / (prop.projw + prop.projh),
			(double)screenw / (prop.projw + prop.projh));
	prop.winh = (prop.projw + prop.projh) * prop.scale;
	prop.winw = (prop.projw + prop.projh) * prop.scale;
	prop.multi = (t_multi){prop.scale * 0.80, prop.scale * 0.80, 0.3
		* prop.scale};
	return (prop);
}

int	main(int argc, char **argv)
{
	t_list			*map;
	t_list			*points;
	t_windata		windata;
	t_properties	prop;

	if (argc < 2 || argc > 2)
		return (0);
	map = ft_parse_map(argv[1]);
	if (!map)
		return (1);
	windata.mlx = mlx_init();
	prop = ft_getprojproperties(((t_zline *)map->content)->length,
			ft_lstsize(map), windata);
	points = ft_getpointsproj(map, 120, prop.multi);
	ft_lstclear(&map, &ft_freedataparse);
	if (!points)
		return (ft_freeproj(&windata), ft_putendl_fd(PROJECTION_FAILED, 2), 1);
	ft_initwinandimg(&windata, prop, "fdf");
	ft_drawlinks(points, &windata, (t_trans){prop.projw * prop.scale
		+ prop.scale / 2, prop.projh / 2 * prop.scale + prop.scale / 2});
	ft_lstclear(&points, &ft_freedatapoints);
	mlx_put_image_to_window(windata.mlx, windata.mlx_win, windata.img, 0, 0);
	ft_hook(&windata);
	mlx_loop(windata.mlx);
	return (0);
}
