/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:32:44 by zweng             #+#    #+#             */
/*   Updated: 2017/11/09 18:37:05 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*ret;

	ret = dst;
	while (1)
	{
		if (!len--)
			return (ret);
		else if ((*dst++ = *src++) == 0)
			break ;
	}
	while (len--)
		*dst++ = 0;
	return (ret);
}
