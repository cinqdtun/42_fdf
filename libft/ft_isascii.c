/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:18:33 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/21 14:21:55 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("Is ascii : %d\n", ft_isascii('1'));
	printf("Is ascii : %d\n", ft_isascii('e'));
	printf("Is ascii : %d\n", ft_isascii('*'));
	printf("Is ascii : %d\n", ft_isascii(232));
	return (1);
}*/