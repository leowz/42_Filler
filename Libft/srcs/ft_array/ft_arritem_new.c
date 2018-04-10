/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arritem_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:46:36 by zweng             #+#    #+#             */
/*   Updated: 2018/03/09 16:14:38 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

t_arritem	ft_arritem_new(void *data, size_t size)
{
	t_arritem	ret;

	ft_bzero(&ret, sizeof(t_arritem));
	if (data && size != 0)
	{
		ret.content = data;
		ret.content_size = size;
	}
	return (ret);
}
