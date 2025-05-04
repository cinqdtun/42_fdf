/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gcalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 09:44:49 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 16:10:01 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *gcalloc(t_list **gcollector, size_t nmemb, size_t size)
{
    void *m;
    
    m = ft_calloc(nmemb, size);
    if (!m || ft_lstadd(gcollector, m) == -1)
    {
        free(m);
        gclean(gcollector);
        write(2, MEM_ALLOC_FAILED, ft_strlen(MEM_ALLOC_FAILED));
        exit(1);
    }
    return (m);
}