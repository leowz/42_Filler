/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlastchr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:02:14 by zweng             #+#    #+#             */
/*   Updated: 2017/11/13 12:07:05 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlastchrp(char const *s)
{
	if (!s)
		return (0);
	if (ft_strlen(s) == 0)
		return ((char *)s);
	while (*s)
		s++;
	return ((char *)(--s));
}