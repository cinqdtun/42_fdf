/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 12:38:46 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 12:18:08 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstfree(t_list **lst)
{
	t_list	*nextn;
	t_list	*content;

	if (!lst || !*lst)
		return ;
	nextn = *lst;
	*lst = NULL;
	while (nextn)
	{
		free(nextn->content);
		content = nextn;
		nextn = nextn->next;
		free(content);
	}
}
