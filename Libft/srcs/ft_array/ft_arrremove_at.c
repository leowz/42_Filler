/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrremove_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 14:29:31 by zweng             #+#    #+#             */
/*   Updated: 2018/03/09 15:25:58 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_arritem	*ft_arrremove_at(t_array *arr, int index)
{
	t_arritem	tmp;
	t_arritem	*ret;

	if (!arr || (int)arr->current_size <= 0 || index < 0 ||
			index > (int)arr->current_size)
		return (NULL);
	if (index == (int)arr->current_size - 1)
	{
		arr->current_size--;
		ret = arr->table + index;
	}
	else
	{
		tmp = arr->table[index];
		ft_memmove(arr->table + index, arr->table + index + 1,
				sizeof(t_arritem) * (arr->current_size - index));
		arr->table[arr->current_size - 1] = tmp;
		ret = arr->table + arr->current_size - 1;
		arr->current_size--;
	}
	return (ret);
}
