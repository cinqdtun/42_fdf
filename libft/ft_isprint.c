/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:22:54 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/21 14:26:14 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
/*
#include <stdio.h>

int	main(void)
{
	printf("Is printable : %d\n", ft_isprint('1'));
	printf("Is printable : %d\n", ft_isprint('e'));
	printf("Is printable : %d\n", ft_isprint(10));
	return (1);
}*/