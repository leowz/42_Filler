/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:29:24 by zweng             #+#    #+#             */
/*   Updated: 2017/11/09 19:06:18 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dp;
	const unsigned char	*sp;

	dp = dst;
	sp = src;
	while (n != 0)
	{
		if ((*dp++ = *sp++) == (unsigned char)c)
			return (dp);
		n--;
	}
	return (0);
}
