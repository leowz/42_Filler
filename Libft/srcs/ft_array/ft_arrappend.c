/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 20:52:32 by zweng             #+#    #+#             */
/*   Updated: 2018/03/09 16:16:32 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int		ft_arrappend(t_array *arr, const t_arritem *item)
{
	if (!arr || !item)
		return (FUN_FAIL);
	if (arr->current_size >= arr->max_size)
	{
		if (!ft_arr_realloc(arr))
			return (FUN_FAIL);
	}
	ft_memcpy(arr->table + arr->current_size, item, sizeof(t_arritem));
	arr->current_size++;
	return (FUN_SUCS);
}

int		ft_arrappend_raw(t_array *arr, void *data, size_t size)
{
	t_arritem	tmp;

	if (!arr || !data)
		return (FUN_FAIL);
	tmp = ft_arritem_new(data, size);
	return (ft_arrappend(arr, &tmp));
}
