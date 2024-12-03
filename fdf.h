/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:19:38 by fdehan            #+#    #+#             */
/*   Updated: 2024/12/03 18:26:54 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "fcntl.h"
# include "libft/libft.h"
# include "limits.h"
# include "mlx/mlx.h"
# include <X11/keysym.h>
# include <math.h>
# include <stdio.h>

# define INT_MAX_C "2147483647"
# define INT_MIN_C "-2147483648"
# define HEXA_SET "0123456789abcdefABCDEF"
# define HEXA_L "0123456789abcdef"
# define HEXA_U "0123456789ABCDEF"
# define PROJECTION_FAILED "FDF: Something went wrong when projecting points"
# define PARSING_ADD_FAILED "FDF: An error has occured on parsing"
# define INVALID_MAP "FDF: The map is invalid"

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
	double		xm;
	double		ym;
	double		zm;
}				t_multi;

typedef struct s_trans
{
	int			xt;
	int			yt;
}				t_trans;

typedef struct s_3dpoint
{
	int			x;
	int			y;
	int			z;
}				t_3dpoint;

typedef struct s_properties
{
	int			winh;
	int			winw;
	double		scale;
	int			projh;
	int			projw;
	t_multi		multi;
}				t_properties;

typedef struct s_windata
{
	void		*mlx;
	void		*mlx_win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	int			closesig;
}				t_windata;

typedef struct s_mapdata
{
	t_list		*map;
}				t_mapdata;

// Parser
void			ft_freedataparse(void *data);
t_list			*ft_parse_map(char *path);
t_pointz		*ft_parsepoint(char *point);
int				ft_contains(char *set, int c);
char			**ft_parse_line(char *line);
int				ft_is_valid_until(char *str, int c);

// Utils
int				ft_splitlen(char **split);
void			ft_freearray(char **arr);
int				ft_abs(int i);
int				ft_max(int i1, int i2);
int				ft_min(int i1, int i2);
char			*ft_gethexaset(char *hexa);
void			ft_freegnl(void);

// Lists funcs
int				ft_lstaddline(t_list **list, int length, int *line);
int				ft_lstaddcoords(t_list **list, int length, t_coords *coords);

// Calc
t_list			*ft_getpointsproj(t_list *map, double rad, t_multi multi);
int				ft_getamplitude(t_list *zmap);
void			ft_freedatapoints(void *data);

// Hook

void			ft_hook(t_windata *windata);

// Drawing funct

int				ft_getcolor(int start, int end, double prog);
void			ft_drawline(t_coords p1, t_coords p2, t_trans trans,
					t_windata *data);
void			ft_drawpoints(t_list *coordsmap, t_inst inst, int color);
void			ft_drawlinks(t_list *coordsmap, t_windata *data, t_trans trans);

#endif