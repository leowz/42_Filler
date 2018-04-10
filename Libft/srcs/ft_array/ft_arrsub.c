/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:15:31 by zweng             #+#    #+#             */
/*   Updated: 2018/03/10 20:42:33 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_array		*ft_arrsub(t_array *arr, int start, int end)
{
	t_array	*ret;

	if (!arr || start < 0 || start >= (int)arr->current_size || end < 0 ||
		end >= (int)arr->current_size || start > end ||
		!(ret = ft_arrnew_size(end - start + 1)))
		return (NULL);
	ret->current_size = end - start + 1;
	ft_memcpy(ret->table, arr->table + start, sizeof(t_arritem) *
			(ret->current_size));
	return (ret);
}
