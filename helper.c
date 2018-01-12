/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 16:06:31 by zweng             #+#    #+#             */
/*   Updated: 2018/01/11 17:20:51 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helper.h"
#include <stdio.h>

void	print_hotmap(t_board bd)
{
	printf("!-------------hotmap %d * %d -----------!\n", bd.height, bd.width);
	int 	i = 0;
	while (i < bd.height)
	{
		int		j = 0;
		while (j < bd.width)
		{
			printf("%3d", bd.hotmap[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("!-------------hotmap %d * %d -----------!\n", bd.height, bd.width);
}
