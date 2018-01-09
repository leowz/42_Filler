/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:51:27 by zweng             #+#    #+#             */
/*   Updated: 2018/01/09 20:41:01 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	pf_get_board_info(t_board *bd)
{
	char	*line;
	int		ret;

	line = 0;
	ret = 0;
	if (get_next_line(STDIN_FILENO, &line) && (ft_strstr(line, "Plateau")))
	{
		if (ft_strchr(line, ' ') && ft_strrchr(line, ' '))
		{
			bd->height = ft_atoi(ft_strchr(line, ' '));
			bd->width = ft_atoi(ft_strrchr(line, ' '));
			ret = 1;
		}
	}
	ft_strdel(&line);
	return (1);
}

static int	pf_alloc_board_map(t_board *bd)
{
	int		i;

	i = 0;
	if (!(bd->board = (char **)malloc(sizeof(char *) * bd->height)))
		return (0);
	if (!(bd->hotmap = (int **)malloc(sizeof(int *) * bd->height)))
		return (0);
	while (i < bd->height)
	{
		if (!(bd->board[i] = ft_strnew(bd->width)))
				return (0);
		if (!(bd->hotmap[i] = (int *)malloc(sizeof(int) * bd->width)))
				return (0);
		i++;
	}
	return (1);
}

static void	pf_init_board_row(t_board *bd, int i)
{
	char	*ptr;
	char	*line;

	line = 0;
	if (get_next_line(STDIN_FILENO, &line))
	{
		ptr = line;
		while (*ptr && !ft_strchr(BD_CHARS, *ptr))
			ptr++;
		ft_strncpy(bd->board[i], ptr, bd->width);
		ft_strdel(&line);
	}
}

int			fl_get_board(t_board *bd)
{
	char	*line;
	int		i;

	line = NULL;
	i = 0;
	if (!pf_get_board_info(bd))
		return (0);
	if (get_next_line(STDIN_FILENO, &line))
		ft_strdel(&line);
	if (bd->board == NULL)
	{
		if (!pf_alloc_board_map(bd))
			return (0);
	}
	while (i < bd->height)
	{
		pf_init_board_row(bd, i);
		i++;
	}
	return (1);
}
