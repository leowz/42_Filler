/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 19:05:10 by zweng             #+#    #+#             */
/*   Updated: 2018/01/18 19:10:58 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *node)
{
	size_t	ret;

	ret = 0;
	if (!node)
		return (ret);
	while (node->next)
	{
		ret++;
		node = node->next;
	}
	return (ret + 1);
}
