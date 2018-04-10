/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:16:55 by zweng             #+#    #+#             */
/*   Updated: 2018/03/09 16:17:07 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int		ft_arrinsert(t_array *arr, const t_arritem *item, int index)
{
	if (!arr || !item || index < 0 || index > (int)arr->current_size)
		return (FUN_FAIL);
	if (arr->current_size >= arr->max_size)
	{
		if (!ft_arr_realloc(arr))
			return (FUN_FAIL);
	}
	ft_memmove(arr->table + index + 1, arr->table + index,
			sizeof(t_arritem) * (arr->current_size - index));
	ft_memcpy(arr->table + index, item, sizeof(t_arritem));
	arr->current_size++;
	return (FUN_SUCS);
}

int		ft_arrinsert_raw(t_array *arr, void *data, size_t size,
		int index)
{
	t_arritem	tmp;

	if (!arr || !data || index < 0 || index > (int)arr->current_size)
		return (FUN_FAIL);
	tmp = ft_arritem_new(data, size);
	return (ft_arrinsert(arr, &tmp, index));
}
