/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:11:43 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 14:26:35 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t get_slen(char const *s, unsigned int start, size_t len)
{
	size_t			slen;
	
	slen = ft_strlen(s);
	if (start > slen)
		return (0);
	else if (slen - start > len)
		return (len);
	return (slen - start);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			slen;
	char			*ptr;

	i = 0;
	if (!s)
		return (NULL);
	slen = get_slen(s, start, len);
	ptr = ft_calloc(slen + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < slen)
	{
		ptr[i] = s[start + i];
		i++;
	}
	return (ptr);
}
