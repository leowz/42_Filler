/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:51:27 by zweng             #+#    #+#             */
/*   Updated: 2018/01/08 14:52:24 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "helper.h"

static int	pf_get_board_info(t_board *bd)
{
	char	*line;
	int		ret;

	line = 0;
	ret = 0;
	if (get_next_line(STD_IN, &line) && (ft_strstr(line, "Plateau")))
	{
		if (ft_strchr(line, ' ') && ft_strrchr(line, ' '))
		{
			bd->height = ft_atoi(ft_strchr(line, ' '));
			bd->width = ft_atoi(ft_strrchr(line, ' '));
			ret = 1;
		}
	}
	free(line);
	return (1);
}

static void	pf_alloc_board_map(t_board *bd)
{
	int		i;

	i = 0;
	bd->board = (char **)malloc(sizeof(char *) * bd->height);
	bd->hotmap = (int **)malloc(sizeof(int *) * bd->height);
	while (i < bd->height)
	{
		bd->board[i] = ft_strnew(bd->width);
		bd->hotmap[i] = (int *)malloc(sizeof(int) * bd->width);
		i++;
	}
}

static void	pf_init_board_row(t_board *bd, int i)
{
	char	*ptr;
	char	*line;

	line = 0;
	if (get_next_line(STD_IN, &line))
	{
		ptr = line;
		while (*ptr && !ft_strchr(BD_CHARS, *ptr))
			ptr++;
		ft_strncpy(bd->board[i], ptr, bd->width);
		free(line);
	}
}

int		fl_get_board(t_board *bd)
{
	char	*line;
	int		i;

	line = 0;
	i = 0;
	if (!pf_get_board_info(bd))
	{
		return (0);
	}
	if (get_next_line(STD_IN, &line))
	{
	//	printf("skip one line\n");
		free(line);
	}
	if (bd->board == 0)
		pf_alloc_board_map(bd);
	//printf("board size %d %d\n", bd->height, bd->width);
	while (i < bd->height)
	{
		pf_init_board_row(bd, i);
		i++;
	}
	//printf("get board\n");
	//print_board(*bd);
	return (1);
}

