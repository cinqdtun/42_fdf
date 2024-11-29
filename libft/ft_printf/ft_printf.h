/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:31:55 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/03 18:55:27 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define CONVERSION_FLAGS "cspdiuxX%"
# define HEXA_SET_L "0123456789abcdef"
# define HEXA_SET_U "0123456789ABCDEF"
# include "../libft.h"

int	ft_printf(const char *str, ...);
int	get_next_var_conv(const char *str, int *start);
int	is_valid_flag(const char *str);
int	print_conversion(va_list args, char arg);
int	ft_print_unsigned_hex_c(unsigned long long n, char *set);
int	ft_print_int_c(int n);
int	ft_print_uint_c(int n);

#endif