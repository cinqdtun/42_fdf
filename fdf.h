/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:35:22 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 22:23:25 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ERROR_USAGE "Usage: ./fdf <map>.fdf"
# define CHUNK_SIZE 1048576
# define MAX_CHUNK_FILE 50
# define EXT ".fdf"
# define ERROR_EXT "Error: The extension should be .fdf"
# define ERROR_OPEN "Error: Failed to open the map"
# define ERROR_MAPSIZE "Error: File too big"
# define ERROR_READ "Error: A problem occured while reading the file"
# define ERROR_EMPTYLINE "Error: Map have at least 1 empty line"
# define ERROR_MEMORY "Error: Memory allocation failed"
# define ERROR_LINEWIDTH "Error: Lines have diffrents size"
# define ERROR_NOTINT "Error: Map contain invalid int"
# define ERROR_COLOR "Error: Map contain an invalid color"
# define ERROR_EMPTYMAP "Error: Map is empty"
# define INT_MAX "2147483647"
# define INT_MIN "2147483648"

# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_point
{
	double	x;
	double	y;
	double	z;
	int		color;
}			t_point;

typedef struct s_fdf
{
	// Program wide variables
	t_list	*garbage;
	size_t	mapHeight;
	size_t	mapWidth;
	t_list	*map;

	// Funcs variables
	char	*filename;
	char	*rawMap;
	char	*rawInt;
	char	*rawColor;
	char	**lineSplit;
	int		chunkRead;
	int		newLinePos;
	int		fd;
	int		x;
	int		y;
	int		digitCount;
	int		startDigit;
	int		i;
	bool	f;
	t_point	*mapLine;
}			t_fdf;

void		readMap(t_fdf *ctx);
void		parseMap(t_fdf *ctx);
void		setPoint(t_fdf *ctx, char *rawPoint);
void		cleanup(t_fdf *ctx, const char *reason);

#endif