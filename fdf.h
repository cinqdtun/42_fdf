/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:19:38 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/29 17:38:48 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fcntl.h"
# include "libft/libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <math.h>
# include <stdio.h>
#include "limits.h"

# define INT_MAX_C "2147483647"
# define INT_MIN_C "-2147483648"
# define HEXA_SET "0123456789abcdefABCDEF"
# define HEXA_L "0123456789abcdef"
# define HEXA_U "0123456789ABCDEF"

typedef struct s_line
{
	int			length;
	int			*line;
}				t_line;

typedef struct s_coords
{
	double		x;
	double		y;
	int			color;
}				t_coords;

typedef struct s_inst
{
	void		*mlx;
	void		*mlx_win;
}				t_inst;

typedef struct s_coordslst
{
	t_coords	*coords;
	int			length;
}				t_coordslst;

typedef struct s_pointz
{
	int			z;
	int			color;
}				t_pointz;

typedef struct s_zline
{
	t_pointz	*zline;
	int			length;
}				t_zline;

typedef struct s_multi
{
	double			xm;
	double			ym;
	double			zm;
}				t_multi;

typedef struct s_trans
{
	int			xt;
	int			yt;
}				t_trans;

// Parser
t_list			*ft_parse_map(char *path);
t_pointz		*ft_parsepoint(char *point);
int				ft_contains(char *set, int c);

// Utils
int				ft_splitlen(char **split);
void			ft_free_array(char **arr);
int				ft_abs(int i);
int				ft_max(int i1, int i2);
int				ft_min(int i1, int i2);
char			*ft_gethexaset(char *hexa);

// Lists funcs
int				ft_lstaddline(t_list **list, int length, int *line);
int				ft_lstaddcoords(t_list **list, int length, t_coords *coords);

// Calc
t_list	*ft_getpointsproj(t_list *map, double rad, t_multi multi);
int	ft_getamplitude(t_list *zmap);

// Drawing funct

int	ft_getcolor(int start, int end, double prog);
void	ft_drawline(t_coords p1, t_coords p2, t_inst inst, t_trans trans);
void			ft_drawpoints(t_list *coordsmap, t_inst inst, int color);
void	ft_drawlinks(t_list *coordsmap, t_inst inst, t_trans trans);

#endif