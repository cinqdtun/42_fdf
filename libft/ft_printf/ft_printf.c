/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:31:10 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/31 14:33:37 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		c;
	int		res;

	va_start(args, str);
	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			res = print_conversion(args, str[i + 1]);
			if (res < 0)
				return (-1);
			c += res;
			i += 2;
			continue ;
		}
		write(1, &str[i], 1);
		c++;
		i++;
	}
	va_end(args);
	return (c);
}

/*int	main(void)
{
	int	*ptr;

	// write(1, CONVERSION_FLAGS, ft_strlen(CONVERSION_FLAGS));
	// ft_printf("HEy %d I wanna %s test my %c parser for %u idiot %c \n",
	//"hey hello", 'I', '&', "Do not print this");
	ptr = malloc(4);
	// printf("Size : %d\n", ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX));
	printf("Size : %d\n", printf("%X \n", ULONG_MAX, -ULONG_MAX));
	printf("Size : %d\n", printf("\"%0-+#6i\"\n", 1, -0));
	free(ptr);
	return (0);
}*/
