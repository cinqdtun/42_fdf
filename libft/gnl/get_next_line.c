/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdehan <fdehan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 22:56:15 by fdehan            #+#    #+#             */
/*   Updated: 2024/11/27 14:32:10 by fdehan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join_buf(char *to_free, char *buff)
{
	char	*ptr;

	if (!to_free)
		return (ft_strdup(buff));
	ptr = ft_strjoin(to_free, buff);
	free(to_free);
	return (ptr);
}

int	ft_check_nl_set_reminder(int fd, char *buff, t_fd_reminder **left_s)
{
	char	*nl;

	nl = ft_strchr(buff, '\n');
	if (!nl)
		return (0);
	if (*left_s)
		free((*left_s)->left);
	else
		*left_s = malloc(sizeof(t_fd_reminder));
	if (!*left_s)
		return (-1);
	(*left_s)->fd = fd;
	(*left_s)->left = ft_strdup(nl + 1);
	return (1);
}

int	ft_read_remind(int fd, char *buff, t_fd_reminder *left_s)
{
	char	*ptr;
	int		c;

	if (!left_s || !left_s->left || fd != left_s->fd || !left_s->left[0])
	{
		c = read(fd, buff, BUFFER_SIZE);
		if (c > 0)
			buff[c] = '\0';
		return (c);
	}
	ptr = left_s->left;
	left_s->left = 0;
	c = ft_strcpy(buff, ptr);
	free(ptr);
	if (c > 0)
		buff[c] = '\0';
	return (c);
}

void	ft_free_everything(t_fd_reminder **left, char **ptr, char **buff,
		int c_read)
{
	free(*buff);
	if (!c_read)
	{
		if (left && *left)
		{
			free((*left)->left);
			(*left)->left = 0;
		}
		free(*left);
		*left = 0;
	}
	if (c_read < 0)
	{
		free(*ptr);
		*ptr = 0;
	}
}

char	*get_next_line(int fd)
{
	static t_fd_reminder	*left = 0;
	char					*buff;
	char					*ptr;
	int						c_read;

	if (fd < 0)
		return (free(left->left), free(left), (char *)0);
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	ptr = 0;
	c_read = 1;
	while (c_read > 0)
	{
		c_read = ft_read_remind(fd, buff, left);
		if (c_read < 1)
			break ;
		ptr = ft_join_buf(ptr, buff);
		if (!ft_check_nl_set_reminder(fd, buff, &left))
			continue ;
		ptr = copy_until_nl(ptr);
		break ;
	}
	ft_free_everything(&left, &ptr, &buff, c_read);
	return (ptr);
}
