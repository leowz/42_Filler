/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 15:52:10 by zweng             #+#    #+#             */
/*   Updated: 2018/01/09 19:40:21 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "get_next_line.h"

# define BD_CHARS ".oOxX"
# define C_P1    'O'
# define C_P2    'X'

typedef	struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_board
{
	int			width;
	int			height;
	char		**board;
	int			**hotmap;
}				t_board;

int				fl_get_piece(t_board *pi);
int				fl_get_board(t_board *pi);
int				fl_resolve(t_board *bd, t_board *piece, int player,
				t_point *res);
void			fl_calc_hotmap(t_board *bd);
int				fl_put_piece(t_board *bd, t_board *pi, t_point *res);
#endif
