/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gadd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:59:42 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 12:28:11 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    gadd(t_list **gcollector, void *ptr)
{
    if (ft_lstadd(gcollector, ptr) == -1)
    {
        gclean(gcollector);
        write(2, MEM_ALLOC_FAILED, ft_strlen(MEM_ALLOC_FAILED));
        exit(1);
    }
}