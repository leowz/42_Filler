/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:31:08 by zweng             #+#    #+#             */
/*   Updated: 2017/12/02 12:35:28 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_prep_line(t_fd *file, void *newline)
{
	int		offset;
	char	*ret;

	offset = (char *)newline - file->buf;
	ret = ft_strsub(file->buf, 0, offset);
	ft_memmove(file->buf, file->buf + offset + 1, file->buf_size - offset);
	file->bytes_read = file->bytes_read - offset - 1;
	ft_bzero(file->buf + file->bytes_read, file->buf_size - file->bytes_read);
	file->ret_flag = 1;
	return (ret);
}

static char		*ft_last_line(t_fd *file)
{
	char	*ret;

	file->open_flag = 0;
	if (file->buf && ft_strlen(file->buf))
	{
		ret = ft_strsub(file->buf, 0, file->bytes_read);
		ft_strdel(&(file->buf));
		file->ret_flag = 1;
		return (ret);
	}
	return (ft_strnew(1));
}

static void		ft_realloc(t_fd *file)
{
	char	*tmp;

	tmp = ft_strnew(file->buf_size * 2);
	ft_memcpy(tmp, file->buf, file->bytes_read);
	free(file->buf);
	file->buf = tmp;
	file->buf_size *= 2;
}

static char		*ft_getline(t_fd *arr, const int fd)
{
	int		read_ret;
	void	*newline;
	t_fd	*file;

	newline = NULL;
	file = arr + fd;
	if (file->bytes_read && file->buf)
		newline = ft_memchr(file->buf, '\n', file->bytes_read);
	while (!newline)
	{
		if (file->bytes_read + BUFF_SIZE > file->buf_size)
			ft_realloc(file);
		read_ret = read(fd, file->buf + file->bytes_read, BUFF_SIZE);
		if (read_ret == 0 || read_ret == -1)
		{
			file->ret_flag = read_ret;
			return (read_ret == 0 ? ft_last_line(file) : NULL);
		}
		file->bytes_read += read_ret;
		newline = ft_memchr(file->buf, '\n', file->bytes_read);
	}
	return (ft_prep_line(file, newline));
}

int				get_next_line(const int fd, char **line)
{
	static	t_fd	array[MAX_FD];

	if (fd < 0 || fd >= MAX_FD || !line)
		return (-1);
	if (array[fd].open_flag == 0)
	{
		array[fd].open_flag = 1;
		array[fd].bytes_read = 0;
		array[fd].buf = ft_strnew(BUFF_SIZE + 1);
		array[fd].buf_size = BUFF_SIZE;
	}
	*line = ft_getline(array, fd);
	return (array[fd].ret_flag);
}
