/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:18:15 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/23 19:31:57 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_addr;
	t_list	*to_del;

	if (!lst || !*lst || !del)
		return ;
	next_addr = *lst;
	*lst = 0;
	while (next_addr)
	{
		del(next_addr->content);
		to_del = next_addr;
		next_addr = next_addr->next;
		free(to_del);
	}
}
