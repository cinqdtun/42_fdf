/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:53:30 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/21 14:14:30 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

/*#include <stdio.h>
int	main(void)
{
	printf("Is alpha : %d\n", ft_isalpha('1'));
	printf("Is alpha : %d\n", ft_isalpha('e'));
	return (1);
}*/
