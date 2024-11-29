/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 09:58:11 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/29 12:55:16 by fdehan           ###   ########.fr       */
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

void	ft_free_array(char **arr)
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

char *ft_gethexaset(char *hexa)
{
	int i;

	i = -1;
	while (++i, hexa[i])
	{
		if (hexa[i] >= 'A' && hexa[i] <= 'Z')
			return (HEXA_SET_U);
		else if(hexa[i] >= 'a' && hexa[i] <= 'z')
			return (HEXA_SET_L);
	}
	return (HEXA_SET_L);
}
