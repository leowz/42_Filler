/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:46:55 by zweng             #+#    #+#             */
/*   Updated: 2017/11/11 12:32:09 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	char	*sp;
	size_t	len;

	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	ret = 0;
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))))
	{
		sp = ret;
		while (len--)
			*sp++ = f(*s++);
		*sp = 0;
	}
	return (ret);
}
