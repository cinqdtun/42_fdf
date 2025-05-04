/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:34:06 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 14:26:05 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	size_t	len;
	char	*ptr;

	i = -1;
	if (!s)
		return (0);
	len = ft_strlen(s);
	ptr = ft_calloc(len + 1, sizeof(char));
	if (!ptr)
		return (0);
	while (s[++i])
		ptr[i] = s[i];
	return (ptr);
}
