/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:02:04 by zweng             #+#    #+#             */
/*   Updated: 2017/11/13 15:09:12 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;

	ret = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		ft_lstappend(&ret, f(lst));
		lst = lst->next;
	}
	return (ret);
}
