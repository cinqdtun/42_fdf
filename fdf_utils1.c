/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:46:06 by fdehan            #+#    #+#             */
/*   Updated: 2024/12/03 16:18:25 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_freegnl(void)
{
	get_next_line(-1);
}

char	*ft_gethexaset(char *hexa)
{
	int	i;

	i = -1;
	while (++i, hexa[i])
	{
		if (hexa[i] >= 'A' && hexa[i] <= 'Z')
			return (HEXA_SET_U);
		else if (hexa[i] >= 'a' && hexa[i] <= 'z')
			return (HEXA_SET_L);
	}
	return (HEXA_SET_L);
}
