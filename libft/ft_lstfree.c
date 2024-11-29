/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:38:46 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/17 16:16:43 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	t_list	*next_addr;
	t_list	*to_del;

	if (!lst || !*lst)
		return ;
	next_addr = *lst;
	*lst = 0;
	while (next_addr)
	{
		free(next_addr->content);
		to_del = next_addr;
		next_addr = next_addr->next;
		free(to_del);
	}
}
