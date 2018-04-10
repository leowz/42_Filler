/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:08:43 by zweng             #+#    #+#             */
/*   Updated: 2018/03/08 22:07:03 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int		ft_arr_realloc(t_array *arr)
{
	t_arritem		*tmp;

	if (!arr || !(tmp = ft_memalloc(sizeof(t_arritem) * arr->max_size * 2)))
		return (FUN_FAIL);
	ft_memcpy(tmp, arr->table, sizeof(t_arritem) * arr->max_size);
	ft_memdel((void **)&(arr->table));
	arr->table = tmp;
	arr->max_size *= 2;
	return (FUN_SUCS);
}
