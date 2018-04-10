/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:10:43 by zweng             #+#    #+#             */
/*   Updated: 2018/03/09 16:09:11 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int		ft_arrswap(t_array *arr, int index1, int index2)
{
	t_arritem	tmp;

	if (!arr || index1 < 0 || index2 < 0 || index1 >= (int)arr->current_size
			|| index2 >= (int)arr->current_size)
		return (FUN_FAIL);
	if (index1 != index2)
	{
		tmp = arr->table[index1];
		arr->table[index1] = arr->table[index2];
		arr->table[index2] = tmp;
	}
	return (FUN_SUCS);
}
