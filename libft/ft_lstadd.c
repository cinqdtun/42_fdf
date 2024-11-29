/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:22:10 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/17 16:16:34 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstadd(t_list **list, void *content)
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
		return (-1);
	ft_lstadd_back(list, new);
	return (0);
}
