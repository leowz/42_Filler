/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_put_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:22:57 by zweng             #+#    #+#             */
/*   Updated: 2018/01/11 19:57:32 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

static int	pf_calc_piece(t_board *bd, t_board *pi, int m, int n)
{
	int		i;
	int		j;
	int		flag;
	int		val;

	i = 0;
	flag = 0;
	val = 0;
	while (i < pi->height)
	{
		j = 0;
		while (j < pi->width)
		{
			if (pi->board[i][j] == '*' && (m + i >= bd->height || m + i < 0 ||
		n + j >= bd->width || n + j < 0 || (bd->hotmap[m + i][n + j] == 0)))
				return (INT_MAX);
			if (pi->board[i][j] == '*' && bd->hotmap[m + i][n + j] == -2)
				flag += 1;
			if (pi->board[i][j] == '*' && bd->hotmap[m + i][n + j] > 0)
				val += bd->hotmap[m + i][n + j];
			j++;
		}
		i++;
	}
	return (flag == 1 ? val : INT_MAX);
}

int			fl_put_piece(t_board *bd, t_board *pi, t_point *res)
{
	int		i;
	int		j;
	int		tmp;
	int		val;

	tmp = INT_MAX;
	i = -pi->height + 1;
	while (i < bd->height)
	{
		j = -pi->width + 1;
		while (j < bd->width)
		{
			val = pf_calc_piece(bd, pi, i, j);
			if ((val != INT_MAX && tmp == INT_MAX) || (tmp == 0 && val > 0
						&& val < INT_MAX) || (val > 0 && val < tmp))
			{
				res->x = i;
				res->y = j;
				tmp = val;
			}
			j++;
		}
		i++;
	}
	return ((tmp == INT_MAX ? 1 : 0));
}
