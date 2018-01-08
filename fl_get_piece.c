/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_get_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 20:14:51 by zweng             #+#    #+#             */
/*   Updated: 2018/01/08 15:21:42 by zweng            ###   ########.fr       */
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
	if (get_next_line(STD_IN, &line) && ft_strstr(line, "Piece"))
	{
		if (ft_strchr(line, ' ') && ft_strrchr(line, ' '))
		{
			bd->height = ft_atoi(ft_strchr(line, ' '));
			bd->width = ft_atoi(ft_strrchr(line, ' '));
			ret = 1;
		}
	}
	//printf("get dimension\n");
	free(line);
	return (1);
}

int		fl_get_piece(t_board *pi)
{
	char	*line;
	int		i;

	line = 0;
	i = 0;
	//ft_putstr("get piece info\n");
	if (!pf_get_board_info(pi))
		return (0);
	//printf("after get piece info\n");
	pi->board = (char **)malloc(sizeof(char *) * pi->height);
	//printf("prep to get piece\n");
	while (i < pi->height)
	{
		pi->board[i] = ft_strnew(pi->width);
		if (get_next_line(STD_IN, &line))
		{
			ft_strncpy(pi->board[i], line, pi->width);
			free(line);
		}
		i++;
	}
	//printf("get piece\n");
	//print_piece(*pi);
	return (1);
}
