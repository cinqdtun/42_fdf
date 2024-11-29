/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 10:57:03 by fdehan            #+#    #+#             */
/*   Updated: 2024/10/28 19:40:05 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb && size && (nmemb * size) / size != nmemb)
		return (0);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (0);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*#include <stdio.h>

int	main(void)
{
	size_t test_cases[][2] = {{5, sizeof(int)}, {10, sizeof(char)}, {3,
		sizeof(double)}, {0, sizeof(int)}, {5, 0}, {0, 0}};

	for (int i = 0; (unsigned long)i < sizeof(test_cases)
		/ sizeof(test_cases[0]); i++)
	{
		size_t nmemb = test_cases[i][0];
		size_t size = test_cases[i][1];
		void *ptr = ft_calloc(nmemb, size);

		printf("Test case %d: nmemb = %zu, size = %zu\n", i + 1, nmemb, size);
		if (ptr == NULL)
		{
			printf("ft_calloc returned NULL\n");
		}
		else
		{
			int is_zero_initialized = 1;
			for (size_t j = 0; j < nmemb * size; j++)
			{
				if (((unsigned char *)ptr)[j] != 0)
				{
					is_zero_initialized = 0;
					break ;
				}
			}
			printf("Memory is %szero-initialized\n",
				is_zero_initialized ? "" : "not ");
			free(ptr);
		}
		printf("\n");
	}

	return (0);
}*/