/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 10:01:18 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 22:33:44 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void gfree(t_list **gcollector, void *ptr)
{
    t_list *node;
    t_list *prev;

    if (!gcollector || !*gcollector)
        return ;
    node = *gcollector;
    if ((*gcollector)->content == ptr)
    {
        *gcollector = node->next;
        free(node->content);
        free(node);
        node = *gcollector;
    }
    while (node && node->next)
    {
        prev = node;
        node = node->next;
        if (node->content == ptr)
        {
            prev->next = node->next;
            free(node->content);
            free(node);
            node = prev->next;
        }
    }
}
