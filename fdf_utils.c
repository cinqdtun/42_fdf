/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:58:11 by fdehan            #+#    #+#             */
/*   Updated: 2024/12/03 16:01:43 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_splitlen(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

void	ft_freearray(char **arr)
{
	int	i;

	if (!arr || !*arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}

int	ft_min(int i1, int i2)
{
	if (i1 > i2)
		return (i2);
	return (i1);
}

int	ft_max(int i1, int i2)
{
	if (i1 < i2)
		return (i2);
	return (i1);
}
