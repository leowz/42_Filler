/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:12:06 by zweng             #+#    #+#             */
/*   Updated: 2017/11/11 18:32:40 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = 0;
	if ((node = (t_list *)malloc(sizeof(t_list))))
	{
		node->content = 0;
		node->content_size = 0;
		node->next = 0;
		if (content && (node->content = malloc(content_size)))
		{
			ft_memcpy(node->content, content, content_size);
			node->content_size = content_size;
		}
	}
	return (node);
}
