/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:57:24 by zweng             #+#    #+#             */
/*   Updated: 2017/11/11 13:09:08 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	flen;
	size_t	slen;

	if (!s1 || !s2)
		return (0);
	ret = 0;
	flen = ft_strlen(s1);
	slen = ft_strlen(s2);
	if ((ret = (char *)malloc(sizeof(char) * (flen + slen + 1))))
	{
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
	}
	return (ret);
}
