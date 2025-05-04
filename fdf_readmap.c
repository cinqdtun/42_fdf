/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_readmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:52:25 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 22:24:10 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	checkExt(t_fdf *ctx)
{
	char	*ext;
	bool	isValid;

	ext = ft_strrchr(ctx->filename, '.');
	isValid = !ft_strcmp(ext, EXT);
	if (!ext || !isValid)
	{
		ft_dprintf(2, ERROR_EXT "\n");
		exit(1);
	}
}

static void	openFile(t_fdf *ctx)
{
	ctx->fd = open(ctx->filename, O_RDONLY);
	if (ctx->fd == -1)
	{
		ft_dprintf(2, ERROR_OPEN "\n");
		exit(1);
	}
}

static ssize_t	readChunk(t_fdf *ctx, char *buf)
{
	ssize_t	readSize;

	if (ctx->chunkRead + 1 > MAX_CHUNK_FILE)
		cleanup(ctx, ERROR_MAPSIZE "\n");
	readSize = read(ctx->fd, buf, CHUNK_SIZE - 1);
	if (readSize == -1)
		cleanup(ctx, ERROR_READ "\n");
	buf[readSize] = '\0';
	return (readSize);
}

static void	readFile(t_fdf *ctx)
{
	char	buf[CHUNK_SIZE];

	while (readChunk(ctx, buf) > 0)
	{
		ctx->rawMap = ft_strjoin(ctx->rawMap, buf);
		gadd(&ctx->garbage, ctx->rawMap);
		ctx->chunkRead++;
	}
}

void	readMap(t_fdf *ctx)
{
	checkExt(ctx);
	openFile(ctx);
	readFile(ctx);
	if (!ctx->rawMap)
		cleanup(ctx, ERROR_EMPTYMAP "\n");
}