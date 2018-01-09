/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_hotmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:23:05 by zweng             #+#    #+#             */
/*   Updated: 2018/01/09 20:18:33 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <limits.h>

static int	pf_bigger(int a, int b)
{
	return (a > b ? a : b);
}

static int	pf_calc_val(t_board *bd, int m, int n)
{
	int		tmp;
	int		val;

	tmp = INT_MAX;
	if (m > 0 && (val = bd->hotmap[m - 1][n]) >= 0)
		tmp = tmp > val ? val : tmp;
	if (m < bd->height - 1 && (val = bd->hotmap[m + 1][n]) >= 0)
		tmp = tmp > val ? val : tmp;
	if (n > 0 && (val = bd->hotmap[m][n - 1]) >= 0)
		tmp = tmp > val ? val : tmp;
	if (n < bd->width - 1 && (val = bd->hotmap[m][n + 1]) >= 0)
		tmp = tmp > val ? val : tmp;
	if (m > 0 && n > 0 && (val = bd->hotmap[m - 1][n - 1]) >= 0)
		tmp = tmp > val ? val : tmp;
	if (m < bd->height - 1 && n < bd->width - 1 &&
			(val = bd->hotmap[m + 1][n + 1]) >= 0)
		tmp = tmp > val ? val : tmp;
	if (n > 0 && m < bd->height - 1 && (val = bd->hotmap[m + 1][n - 1]) >= 0)
		tmp = tmp > val ? val : tmp;
	if (n < bd->width - 1 && m > 0 && (val = bd->hotmap[m - 1][n + 1]) >= 0)
		tmp = tmp > val ? val : tmp;
	if (tmp != INT_MAX)
		bd->hotmap[m][n] = tmp + 1;
	return (tmp != INT_MAX ? 1 : 0);
}

void		fl_calc_hotmap(t_board *bd)
{
	int		flag;
	int		l;
	int		m;
	int		n;

	l = 0;
	while (l < (pf_bigger(bd->width, bd->height)))
	{
		m = 0;
		flag = 0;
		while (m < bd->height)
		{
			n = 0;
			while (n < bd->width)
			{
				if (bd->hotmap[m][n] == -1 || bd->hotmap[m][n] > 0)
					flag += pf_calc_val(bd, m, n);
				n++;
			}
			m++;
		}
		if (flag == 0)
			break ;
		l++;
	}
}

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
			if (pi->board[i][j] == '*' && (m + i >= bd->height ||
				n + j >= bd->width || (bd->hotmap[m + i][n + j] == 0)))
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

	i = 0;
	tmp = INT_MAX;
	while (i < bd->height)
	{
		j = 0;
		while (j < bd->width)
		{
			val = pf_calc_piece(bd, pi, i, j);
			if (val < tmp)
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
