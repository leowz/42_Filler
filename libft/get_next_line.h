/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 12:31:32 by zweng             #+#    #+#             */
/*   Updated: 2018/01/09 15:20:43 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# define BUFF_SIZE 32
# define MAX_FD 2048

typedef struct	s_fd
{
	int			fd;
	int			open_flag;
	size_t		bytes_read;
	char		*buf;
	size_t		buf_size;
	int			ret_flag;
}				t_fd;

int				get_next_line(const int fd, char **line);
#endif
