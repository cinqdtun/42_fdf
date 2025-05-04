/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_parseutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 17:36:06 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 22:26:28 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    checkColor(t_fdf *ctx)
{
    if (!ctx->rawColor)
        ctx->mapLine[ctx->x].color = 0xFFFFFF;
    if (ft_strncmp(ctx->rawColor, "0x", 2) != 0)
        cleanup(ctx, ERROR_NOTINT "\n");
    ctx->i = 1;
    while (ctx->rawColor[++ctx->i])
    {
        //if (ft_isdigit(ctx->rawColor[ctx->i]) || ctx->rawColor[ctx->i] <)
    }
}

static void	checkOverflow(t_fdf *ctx)
{
	if (ctx->digitCount < 10)
		return ;
	else if (ctx->digitCount == 10)
	{
		if (ctx->rawInt[0] == '-' && ft_strcmp(&ctx->rawInt[ctx->startDigit],
				INT_MIN) < 0)
			return ;
		else if (ft_strcmp(&ctx->rawInt[ctx->startDigit], INT_MAX) < 0)
			return ;
	}
	cleanup(ctx, ERROR_NOTINT "\n");
}

static void	checkInt(t_fdf *ctx)
{
    ctx->i = -1;
	ctx->f = false;
	ctx->digitCount = 0;
	ctx->startDigit = -1;
	ctx->i += ctx->rawInt[0] == '-' || ctx->rawInt[0] == '+';
	while (ctx->rawInt[++ctx->i])
	{
		if (!ft_isdigit(ctx->rawInt[ctx->i]))
			cleanup(ctx, ERROR_NOTINT "\n");
		else if (ctx->startDigit == -1 && 0 < ctx->rawInt[ctx->i])
			ctx->startDigit = ctx->i;
		ctx->f = true;
	}
	if (!ctx->f)
		cleanup(ctx, ERROR_NOTINT "\n");
	ctx->digitCount = ctx->i - ctx->startDigit;
	checkOverflow(ctx);
}

void	setPoint(t_fdf *ctx, char *rawPoint)
{
    ctx->rawInt = rawPoint;
	ctx->rawColor = ft_strchr(rawPoint, ',');
	if (ctx->rawColor)
	{
		ctx->rawColor[0] = '\0';
		ctx->rawColor++;
	}
    checkInt(ctx);
    ctx->mapLine[ctx->x].x = ctx->x;
    ctx->mapLine[ctx->x].y = ctx->y;
    ctx->mapLine[ctx->x].z = ft_atoi(rawPoint);
    ctx->mapLine[ctx->x].color = 0xFFFFFF;
}