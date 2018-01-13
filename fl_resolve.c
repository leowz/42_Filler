/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:50:34 by zweng             #+#    #+#             */
/*   Updated: 2018/01/13 14:44:29 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	pf_ennemy_char(int player)
{
	return (player == 2 ? 'O' : 'X');
}

static char	pf_player_char(int player)
{
	return (player == 1 ? 'O' : 'X');
}

static void	pf_init_hotmap(t_board *bd, int player)
{
	int		i;
	int		j;

	i = 0;
	while (i < bd->height)
	{
		j = 0;
		while (j < bd->width)
		{
			if (bd->board[i][j] == '.')
				bd->hotmap[i][j] = -1;
			else if (bd->board[i][j] == pf_ennemy_char(player) ||
					bd->board[i][j] == pf_ennemy_char(player) + 'a' - 'A')
				bd->hotmap[i][j] = 0;
			else if (bd->board[i][j] == pf_player_char(player) ||
					bd->board[i][j] == pf_player_char(player) + 'a' - 'A')
				bd->hotmap[i][j] = -2;
			j++;
		}
		i++;
	}
}

int			fl_resolve(t_board *bd, t_board *piece, int player, t_point *res)
{
	int		ret;

	pf_init_hotmap(bd, player);
	fl_calc_hotmap(bd);
	ret = fl_put_piece(bd, piece, res);
	if (ret == 1)
	{
		res->x = 0;
		res->y = 0;
	}
	return (ret);
}
