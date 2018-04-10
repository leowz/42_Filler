/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:57:23 by zweng             #+#    #+#             */
/*   Updated: 2017/11/09 14:08:56 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*ret;

	len = ft_strlen(s1) + 1;
	if (!(ret = malloc(sizeof(*s1) * len)))
		return (0);
	ft_memcpy(ret, s1, len);
	return (ret);
}
