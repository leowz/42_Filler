/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:00:58 by zweng             #+#    #+#             */
/*   Updated: 2017/11/11 12:15:33 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				ret;
	unsigned int	digit;
	int				sign;
	int				i;

	ret = 0;
	sign = 0;
	i = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str
			== '\f' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
		sign = *str++ == '-' ? 1 : 0;
	while (1 && i < 20)
	{
		digit = *str++ - '0';
		if (digit > 9)
			break ;
		ret = (10 * ret) + digit;
		i++;
	}
	if (sign)
		return (i < 20 ? -ret : 0);
	return (i < 20 ? ret : -1);
}
