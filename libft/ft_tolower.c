/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 20:18:53 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 19:41:51 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*#include <stdio.h>

int	main(void)
{
	printf("Converting \'A\' to lower . \'%c\'\n", ft_tolower('A'));
	printf("Converting \'T\' to lower . \'%c\'\n", ft_tolower('T'));
	printf("Converting \'w\' to lower . \'%c\'\n", ft_tolower('w'));
	printf("Converting \'*\' to lower . \'%c\'\n", ft_tolower('*'));
	return (1);
}*/