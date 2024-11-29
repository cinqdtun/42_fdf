/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:56:34 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/18 11:31:35 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strcpy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

char	*copy_until_nl(char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
	{
		ptr = malloc(i + 2);
		ptr[i + 1] = 0;
	}
	else
		ptr = malloc(i + 1);
	if (!ptr)
		return (0);
	ptr[i] = str[i];
	while (i-- > 0)
		ptr[i] = str[i];
	free(str);
	return (ptr);
}
