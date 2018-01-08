/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:43:27 by zweng             #+#    #+#             */
/*   Updated: 2018/01/07 20:24:10 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"

void	print_piece(t_board bd)
{
	int		i = 0;

	printf("#------Piece %d * %d-------#\n", bd.height, bd.width);
	while (i < bd.height)
		printf("%s \n", bd.board[i++]);
	printf("#------Piece-------#\n");
}

void	print_board(t_board bd)
{
	int		i = 0;

	printf("#------Board %d * %d-------#\n", bd.height, bd.width);
	while (i < bd.height)
		printf("%s \n", bd.board[i++]);
	printf("#------Board-------#\n");
}

void	print_hotmap(t_board bd)
{
	int		i = 0;
	int		j = 0;

	printf("#------Hotmap-------#\n");
	while (i < bd.height)
	{
		j = 0;
		while (j < bd.width)
		{
			printf("%5d", bd.hotmap[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("#------Hotmap-------#\n");
}
