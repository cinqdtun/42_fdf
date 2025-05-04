/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:31:55 by fdehan            #+#    #+#             */
/*   Updated: 2025/05/04 14:45:56 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# define CONVERSION_FLAGS "cspdiuxX%"
# define HEXA_SET_L "0123456789abcdef"
# define HEXA_SET_U "0123456789ABCDEF"
# include "../libft.h"

int	ft_dprintf(int fd, const char *str, ...);
int	get_next_var_conv(const char *str, int *start);
int	is_valid_flag(const char *str);
int	print_conversion(int fd, va_list args, char arg);
int	ft_print_unsigned_hex_c(int fd, unsigned long long n, char *set);
int	ft_print_int_c(int fd, int n);
int	ft_print_uint_c(int fd, int n);

#endif