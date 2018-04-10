/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arritem_at.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 21:17:30 by zweng             #+#    #+#             */
/*   Updated: 2018/03/08 22:06:35 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_arritem	*ft_arritem_at(t_array *arr, int index)
{
	if (!arr || index < 0 || index > (int)arr->current_size)
		return (NULL);
	return (arr->table + index);
}
