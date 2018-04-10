/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:09:23 by zweng             #+#    #+#             */
/*   Updated: 2017/11/11 12:14:22 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t n;

	n = ft_strlen(needle);
	if (n == 0)
		return ((char *)haystack);
	while (*haystack)
	{
		if (!ft_memcmp(haystack, needle, n))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
