/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:27:05 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 20:20:25 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

/*#include <stdio.h>

int	main(void)
{
	char str[] = "This is a test";
	printf("Len of \"%s\" is %ld\n", str, ft_strlen(str));
	char str2[] = "";
	printf("Len of \"%s\" is %ld\n", str, ft_strlen(str2));
	return (1);
}*/
