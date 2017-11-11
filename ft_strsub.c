/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:44:53 by zweng             #+#    #+#             */
/*   Updated: 2017/11/11 12:56:59 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	char	*sp;

	if (!s)
		return (0);
	ret = 0;
	if ((ret = (char *)malloc(sizeof(char) * (len + 1))))
	{
		sp = ret;
		while (len--)
			*sp++ = *(s++ + start);
		*sp = 0;
	}
	return (ret);
}
