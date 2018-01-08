/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:52:01 by zweng             #+#    #+#             */
/*   Updated: 2018/01/08 18:38:03 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	pf_free_board(t_board *board)
{
	int		i;

	i = 0;
	while (i < board->height)
		free(board->board[i++]);
	free(board->board);
	if (board->hotmap)
	{
		i = 0;
		while (i < board->height)
			free(board->hotmap[i++]);
		free(board->hotmap);
	}
	board->width = 0;
	board->height = 0;
}

static void	pf_output_result(t_point res)
{
	ft_putnbr(res.x);
	ft_putstr(" ");
	ft_putnbr(res.y);
	ft_putstr("\n");
}

static int	pf_get_player(void)
{
	char	*line;
	int		ret;

	line = 0;
	ret = 0;
	get_next_line(STD_IN, &line);
	if (line && ft_strstr(line, "$$$ exec") && ft_strstr(line, "zweng.filler"))
	{
		if (ft_strstr(line, "p1"))
			ret = 1;
		else if (ft_strstr(line, "p2"))
			ret = 2;
	}
	free(line);
	return (ret);
}

static void	pf_init_board(t_board *bd)
{
	bd->width = 0;
	bd->height = 0;
	bd->board = 0;
	bd->hotmap = 0;
}

int			main(void)
{
	int		player;
	t_point	res;
	t_board	board;
	t_board piece;
	int		val;

	pf_init_board(&board);
	pf_init_board(&piece);
	if (!(player = pf_get_player()))
		return (1);
	while (1)
	{
		val = 0;
		val += fl_get_board(&board);
		val += fl_get_piece(&piece);
		if (val != 2)
			return (1);
		val = fl_resolve(&board, &piece, player, &res);
		pf_output_result(res);
		pf_free_board(&piece);
		if (val == 1)
			break ;
	}
	pf_free_board(&board);
	return (0);
}
