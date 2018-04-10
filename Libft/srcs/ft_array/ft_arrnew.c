/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:56:48 by zweng             #+#    #+#             */
/*   Updated: 2018/03/09 16:49:19 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_array		*ft_arrnew(void)
{
	t_array		*ret;

	ret = NULL;
	if (!(ret = ft_memalloc(sizeof(t_array))) ||
		!(ret->table = ft_memalloc(sizeof(t_arritem) * ARRAY_SIZE)))
		return (NULL);
	ret->max_size = ARRAY_SIZE;
	return (ret);
}

t_array		*ft_arrnew_size(size_t size)
{
	t_array		*ret;

	ret = NULL;
	if (!(ret = ft_memalloc(sizeof(t_array))) ||
		!(ret->table = ft_memalloc(sizeof(t_arritem) * size)))
		return (NULL);
	ret->max_size = size;
	return (ret);
}

t_array		*ft_arrnew_arr(t_array *arr)
{
	t_array		*ret;

	ret = NULL;
	if (!(ret = ft_memalloc(sizeof(t_array))) ||
		!(ret->table = ft_memalloc(sizeof(t_arritem) * arr->max_size)))
		return (NULL);
	ret->current_size = arr->current_size;
	ret->max_size = arr->max_size;
	ft_memcpy(ret->table, arr->table, sizeof(t_arritem) * arr->max_size);
	return (ret);
}
