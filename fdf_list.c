/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 13:56:45 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/28 16:10:38 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_lstaddline(t_list **list, int length, int *line)
{
    t_list *node;
    t_line *data;

    node = malloc(sizeof(t_list));
    if (!node)
        return (0);
    data = malloc(sizeof(t_line));
    if (!data)
        return (free(node), 0);
    data->length = length;
    data->line = line;
    node->content = data;
    node->next = 0;
    ft_lstadd_back(list, node);
    return (1);
}

int ft_lstaddcoords(t_list **list, int length, t_coords *coords)
{
    t_list *node;
    t_coordslst *data;

    node = malloc(sizeof(t_list));
    if (!node)
        return (0);
    data = malloc(sizeof(t_coordslst));
    if (!data)
        return (free(node), 0);
    data->length = length;
    data->coords = coords;
    node->content = data;
    node->next = 0;
    ft_lstadd_back(list, node);
    return (1);
}