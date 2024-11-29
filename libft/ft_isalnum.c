/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:28:04 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/21 14:17:49 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0'
			&& c <= '9'));
}
/*
#include <stdio.h>

int	main(void)
{
	printf("Is alpha or num : %d\n", ft_isalnum('1'));
	printf("Is alpha or num : %d\n", ft_isalnum('e'));
	printf("Is alpha or num : %d\n", ft_isalnum('*'));
	return (1);
}*/