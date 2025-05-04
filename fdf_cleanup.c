/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cleanup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:51:56 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 17:37:47 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    cleanup(t_fdf *ctx, const char *reason)
{
    if (reason)
        ft_dprintf(2, reason);
    free_split(ctx->lineSplit);
    ft_lstfree(&ctx->map);
    gclean(&ctx->garbage);
    exit(1);
}