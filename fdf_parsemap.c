/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parsemap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 16:35:43 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 22:47:45 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void allocateMapLine(t_fdf *ctx)
{
    size_t len;

    len = 0;
    while (ctx->lineSplit[len])
        len++;
    if (ctx->mapWidth != 0 && len != ctx->mapWidth)
        cleanup(ctx, ERROR_LINEWIDTH "\n");
    ctx->mapLine = ft_calloc(len, sizeof(t_point));
    if (!ctx->mapLine || ft_lstadd(&ctx->map, ctx->mapLine) == -1)
        cleanup(ctx, ERROR_MEMORY "\n");
}

void transformSplitLine(t_fdf *ctx)
{
    ctx->x = -1;
    ctx->y++;
    if (!ctx->lineSplit[0])
        cleanup(ctx, ERROR_EMPTYLINE "\n");
    allocateMapLine(ctx);
    while (ctx->lineSplit[++ctx->x])
        setPoint(ctx, ctx->lineSplit[ctx->x]);
}

void transformLine(t_fdf *ctx, char *line)
{
    ctx->lineSplit = ft_split(line, ' ');
    if (!ctx->lineSplit)
        cleanup(ctx, ERROR_MEMORY "\n");
    transformSplitLine(ctx);
    free_split(ctx->lineSplit);
    ctx->lineSplit = NULL;
}
#include <stdio.h>
void parseLine(t_fdf *ctx)
{
    char    *startLinePos;
    char    *newLinePos;
    char    *currLine;

    startLinePos = ctx->rawMap + ctx->newLinePos;
    newLinePos = ft_strchr(startLinePos, '\n');
    if (newLinePos)
        currLine = ft_strndup(startLinePos, newLinePos - startLinePos);
    else if (!newLinePos)
        currLine = ft_strdup(startLinePos);
    gadd(&ctx->garbage, currLine);
    //printf("Test %s %ld\n", currLine, newLinePos - startLinePos);
    if (ft_strcmp("\n", newLinePos))
        transformLine(ctx, currLine);
    gfree(&ctx->garbage, currLine);
    if (newLinePos != NULL)
        ctx->newLinePos = (int)(newLinePos - ctx->rawMap + 1);
    else
        ctx->newLinePos = 0;
}

#include "stdio.h"
void parseMap(t_fdf *ctx)
{
    parseLine(ctx);
    while (ctx->newLinePos)
        parseLine(ctx);
}