/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:41:35 by zweng             #+#    #+#             */
/*   Updated: 2017/11/11 12:28:40 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t				len;
	unsigned int		i;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (len--)
		f(i++, s++);
}
