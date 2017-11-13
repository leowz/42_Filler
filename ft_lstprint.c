/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:20:52 by zweng             #+#    #+#             */
/*   Updated: 2017/11/13 14:45:04 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *alst)
{
	if (!alst)
		return ;
	while (alst)
	{
		ft_putstr((char *)(alst->content));
		ft_putstr("--->");
		alst = alst->next;
	}
	ft_putstr("NULL");
}
