/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:34:06 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 22:42:19 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	size_t	len;
	char	*ptr;

	i = 0;
	len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (len < n)
		ptr = ft_calloc(len + 1, sizeof(char));
	else
		ptr = ft_calloc(n + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (s[i] && i < n)
	{
		ptr[i] = s[i];
		++i;
	}
	return (ptr);
}
