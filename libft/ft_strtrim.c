/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 13:37:45 by zweng             #+#    #+#             */
/*   Updated: 2017/11/13 15:16:49 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		pft_iswhitespace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v');
}

char			*ft_strtrim(char const *s)
{
	char const	*fp;
	char const	*sp;

	if (!s)
		return (0);
	fp = s;
	sp = s;
	while (*sp)
		sp++;
	sp--;
	while ((pft_iswhitespace(*fp) || pft_iswhitespace(*sp)) && fp <= sp)
	{
		if (pft_iswhitespace(*fp))
			fp++;
		if (pft_iswhitespace(*sp))
			sp--;
	}
	if (sp < fp)
		return (ft_strnew(0));
	return (ft_strsub(s, fp - s, sp - fp + 1));
}
