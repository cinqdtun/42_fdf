/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:19:02 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/29 18:01:26 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int main(int argc, char **argv)
{
    void	*mlx;
	void	*mlx_win;
    double  ratio;
	t_data	image;
    t_list *points;
    t_multi mult;
    
    mlx = mlx_init();
	
    if (argc < 2)
        return (0);
    t_list *map  = ft_parse_map(argv[1]);
    ft_printf("%p", map);
    ratio = (double)ft_lstsize(map) / ((t_zline *)map->content)->length;
    /*mult.ym = 500.0 / ft_lstsize(map);
    mult.xm = 500.0 / ((t_zline *)map->content)->length;
    mult.zm = 500.0 / ft_getamplitude(map) / 5;*/

    mult.xm = 1 * 9;
    mult.ym = 1 * 9;
    mult.zm = 1 * 9;
    
    ft_printf("Amplitude : %d", mult.zm);
    /*if (ft_lstsize(map) > ((t_zline *)map->content)->length)
    {
        if (ft_lstsize(map) < 1000)
        {
            mult.ym = 1000.0 / ft_lstsize(map);
            mult.xm = 1000.0 / ((t_zline *)map->content)->length;
        }
    }*/
    points = ft_getpointsproj(map, 120, mult);
    ft_printf("Points :%p", map);
    mlx_win = mlx_new_window(mlx, mult.xm * ((t_zline *)map->content)->length * 2, mult.ym * ft_lstsize(map) * 2, "fdf");
	image.img = mlx_new_image(mlx,mult.xm * ((t_zline *)map->content)->length * 2, mult.ym * ft_lstsize(map) * 2);
    ft_drawlinks(points, (t_inst){mlx, mlx_win}, (t_trans){mult.xm * ((t_zline *)map->content)->length, mult.ym * ft_lstsize(map) / 2});
    //ft_drawline((t_coords){10, 10, 0x000000FF}, (t_coords){100, 30, 0x00FFFFFF}, (t_inst){mlx, mlx_win});
    //ft_drawpoints(points, (t_inst){mlx, mlx_win}, 0x00FF0000);
    
    mlx_loop(mlx);
    return (0);
}