/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 12:47:17 by fdehan            #+#    #+#             */
/*   Updated: 2024/12/03 16:01:04 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	ft_onclose(t_windata *windata)
{
	mlx_destroy_image(windata->mlx, windata->img);
	mlx_destroy_window(windata->mlx, windata->mlx_win);
	mlx_destroy_display(windata->mlx);
	free(windata->mlx);
	exit(0);
	return (0);
}

static int	ft_onclosekey(int key, t_windata *windata)
{
	if (key == XK_Escape)
	{
		mlx_destroy_image(windata->mlx, windata->img);
		mlx_destroy_window(windata->mlx, windata->mlx_win);
		mlx_destroy_display(windata->mlx);
		free(windata->mlx);
		exit(0);
	}
	return (0);
}

void	ft_hook(t_windata *windata)
{
	mlx_hook(windata->mlx_win, 17, 0, &ft_onclose, windata);
	mlx_key_hook(windata->mlx_win, &ft_onclosekey, windata);
}
