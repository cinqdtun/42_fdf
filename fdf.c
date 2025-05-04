/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:35:59 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 17:50:32 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char** argv)
{
    t_fdf ctx;

    if (argc != 2)
    {
        ft_dprintf(2, ERROR_USAGE"\n");
        return (1);
    }
    ctx.garbage = NULL;
    ctx.filename = argv[1];
    ctx.chunkRead = 0;
    ctx.rawMap = NULL;
    ctx.newLinePos = 0;
    ctx.lineSplit = NULL;
    ctx.map = NULL;
    ctx.mapHeight = 0;
    ctx.mapWidth = 0;
    readMap(&ctx);
    cleanup(&ctx, NULL);
    return (0);
}
