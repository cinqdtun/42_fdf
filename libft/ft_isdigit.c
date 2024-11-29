/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 13:04:28 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/21 14:14:39 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/*#include <stdio.h>
int	main(void)
{
	printf("Is digit : %d\n", ft_isdigit('1'));
	printf("Is digit : %d\n", ft_isdigit('e'));
	return (1);
}*/