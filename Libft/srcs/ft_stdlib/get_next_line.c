/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:31:08 by zweng             #+#    #+#             */
/*   Updated: 2018/03/13 14:26:21 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_prep_line(t_fd *file, void *newline)
{
	int		offset;
	char	*ret;

	if (!file || !newline)
		return (NULL);
	offset = (char *)newline - file->buf;
	if (!(ret = ft_strsub(file->buf, 0, offset)))
		return (NULL);
	ft_memmove(file->buf, file->buf + offset + 1, file->buf_size - offset);
	file->bytes_read = file->bytes_read - offset - 1;
	ft_bzero(file->buf + file->bytes_read, file->buf_size - file->bytes_read);
	file->ret_flag = 1;
	return (ret);
}

static char		*ft_last_line(t_fd *file)
{
	char	*ret;

	if (!file)
		return (NULL);
	file->open_flag = 0;
	if (file->buf && ft_strlen(file->buf))
	{
		if (!(ret = ft_strsub(file->buf, 0, file->bytes_read)))
			return (NULL);
		ft_strdel(&(file->buf));
		file->ret_flag = 1;
		return (ret);
	}
	return (ft_strnew(1));
}

static t_fd		*ft_realloc(t_fd *file)
{
	char	*tmp;

	if (!file || !(tmp = ft_strnew(file->buf_size * 2)))
		return (NULL);
	ft_memcpy(tmp, file->buf, file->bytes_read);
	ft_strdel(&(file->buf));
	file->buf = tmp;
	file->buf_size *= 2;
	return (file);
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
		{
			if (!(ft_realloc(file)))
				return (NULL);
		}
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
		if (!(array[fd].buf = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
		array[fd].buf_size = BUFF_SIZE;
	}
	if (!(*line = ft_getline(array, fd)))
		return (-1);
	return (array[fd].ret_flag);
}
