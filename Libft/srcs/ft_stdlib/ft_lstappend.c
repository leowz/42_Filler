/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:50:56 by zweng             #+#    #+#             */
/*   Updated: 2017/11/13 15:08:50 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *node)
{
	t_list	*nnode;
	t_list	*lstp;

	nnode = ft_lstnew(node->content, node->content_size);
	lstp = *alst;
	if (!alst || !nnode)
		return ;
	if (!(*alst))
	{
		*alst = nnode;
		return ;
	}
	while (lstp->next)
		lstp = lstp->next;
	lstp->next = nnode;
}
