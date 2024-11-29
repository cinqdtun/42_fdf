/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:12:01 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/21 20:18:31 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*#include <stdio.h>

int	main(void)
{
	printf("Converting \'a\' to upper . \'%c\'\n", ft_toupper('a'));
	printf("Converting \'t\' to upper . \'%c\'\n", ft_toupper('t'));
	printf("Converting \'W\' to upper . \'%c\'\n", ft_toupper('W'));
	printf("Converting \'*\' to upper . \'%c\'\n", ft_toupper('*'));
	return (1);
}*/