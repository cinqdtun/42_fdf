/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:56:50 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/18 11:34:27 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "../libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct fd_reminder_s
{
	int		fd;
	char	*left;
}			t_fd_reminder;

char		*get_next_line(int fd);
int			ft_strcpy(char *dst, char *src);
char		*copy_until_nl(char *str);

#endif
