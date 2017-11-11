/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:38:11 by zweng             #+#    #+#             */
/*   Updated: 2017/11/11 16:51:24 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pft_aux(int n, char **str)
{
	int		digit;

	digit = n % 10 > 0 ? n % 10 : -(n % 10);
	if (n <= -10 || n >= 10)
		pft_aux(n / 10, str);
	**str = '0' + digit;
	(*str)++;
}

char	*ft_itoa(int n)
{
	char	*ret;
	char	buf[12];
	char	*sp;

	ret = 0;
	sp = buf;
	if (n < 0)
		*sp++ = '-';
	pft_aux(n, &sp);
	*(sp++) = 0;
	ret = ft_strdup(buf);
	return (ret);
}
