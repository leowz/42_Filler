/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 18:04:47 by zweng             #+#    #+#             */
/*   Updated: 2017/11/11 18:34:04 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char const *s)
{
	char	*fp;
	char	*tp;

	if (!s)
		return (0);
	fp = (char *)s;
	tp = ft_strlastchrp(s);
	while (fp < tp)
	{
		if (*fp != *tp)
		{
			*fp = (*fp) ^ (*tp);
			*tp = (*tp) ^ (*fp);
			*fp = (*fp) ^ (*tp);
		}
		fp++;
		tp--;
	}
	return ((char *)s);
}
