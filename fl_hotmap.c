/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fl_hotmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 16:23:05 by zweng             #+#    #+#             */
/*   Updated: 2018/01/08 16:26:40 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include "helper.h"
#include <limits.h>

static int	pf_bigger(int a, int b)
{
	return (a > b ? a : b);
}

static int	pf_calc_val(t_board *bd, int m, int n)
{
	int		tmp;
	int		val;

	//printf("cal val index x %d, y %d\n", m, n);
	//printf("bd size %d * %d", bd->height, bd->width);
	tmp = INT_MAX;
	//printf("start conditions\n");
	if (m > 0 && (val = bd->hotmap[m - 1][n]) >= 0)
	{	
	//	ft_putstr("check 2\n");
		tmp = tmp > val ? val : tmp;
	}
	if (m < bd->height - 1 && (val = bd->hotmap[m + 1][n]) >= 0)
	{
	//	ft_putstr("check 6\n");
		tmp = tmp > val ? val : tmp;
	}
	if (n > 0 && (val = bd->hotmap[m][n - 1]) >= 0)
	{
	//	ft_putstr("check 8\n");
		tmp = tmp > val ? val : tmp;
	}
	if (n < bd->width - 1 && (val = bd->hotmap[m][n + 1]) >= 0)
	{
	//	ft_putstr("check 4\n");
		tmp = tmp > val ? val : tmp;
	}
	if (m > 0 && n > 0 && (val = bd->hotmap[m - 1][n - 1]) >= 0)
	{
	//	ft_putstr("check 1\n");
		tmp = tmp > val ? val : tmp;
	}
	if (m < bd->height - 1 && n < bd->width - 1 &&
			(val = bd->hotmap[m + 1][n + 1]) >= 0)
	{
	//	ft_putstr("check 5\n");
		tmp = tmp > val ? val : tmp;
	}
	if (n > 0 && m < bd->height - 1 && (val = bd->hotmap[m + 1][n - 1]) >= 0)
	{
	//	ft_putstr("check 7\n");
		tmp = tmp > val ? val : tmp;
	}
	if (n < bd->width - 1 && m > 0 && (val = bd->hotmap[m - 1][n + 1]) >= 0)
	{
	//	ft_putstr("check 3\n");
		tmp = tmp > val ? val : tmp;
	}
	//printf("end conditions\n");
	if (tmp != INT_MAX)
	{
		bd->hotmap[m][n] = tmp + 1;
		return (1);
	}
	return (0);
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
				//printf("l %d m %d n %d\n", l, m, n);
				if (bd->hotmap[m][n] == -1 || bd->hotmap[m][n] > 0)
					flag += pf_calc_val(bd, m, n);
				n++;
				//printf("after calc va\n");
			}
			m++;
		}
	//	print_hotmap(*bd);
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
			if (pi->board[i][j] == '*' && (m + i >= bd->height || n + j >= bd->width ||
						(bd->hotmap[m + i][n + j] == 0)))
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
