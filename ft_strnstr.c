/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:32:49 by zweng             #+#    #+#             */
/*   Updated: 2017/11/13 16:06:25 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	slen;

	slen = ft_strlen(needle);
	if (slen == 0)
		return ((char *)haystack);
	while (*haystack && len >= slen)
	{
		if (!ft_memcmp(haystack, needle, slen))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (0);
}
