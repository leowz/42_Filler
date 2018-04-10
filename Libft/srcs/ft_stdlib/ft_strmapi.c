/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:02:36 by zweng             #+#    #+#             */
/*   Updated: 2017/11/11 12:32:34 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	char			*sp;
	size_t			len;
	unsigned int	i;

	if (!s || !f)
		return (0);
	ret = 0;
	len = ft_strlen(s);
	i = 0;
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))))
	{
		sp = ret;
		while (len--)
			*sp++ = f(i++, *s++);
		*sp = 0;
	}
	return (ret);
}
