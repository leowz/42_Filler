/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 13:37:51 by zweng             #+#    #+#             */
/*   Updated: 2017/12/25 13:50:32 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_aux(long long int val, int base, char **p)
{
	char	*base_str = "0123456789ABCDEF";
	int		tmp;

	if (val >= base || val <= -base)
		ft_aux(val / base, base, p);
	tmp = (int)(val % base);
	*(*p)++ = *(base_str + ABS(tmp));
}

char	*ft_itoa_base(long long int value, int base)
{
	char	*ret;
	char	*p;

	if (base < 2 || base > 16 || !(ret = (char *)malloc(70)))
		return (0);
	p = ret;
	if (value < 0 && base == 10)
		*p++ = '-';
	ft_aux(value, base, &p);
	*p = 0;
	return (ret);	
}