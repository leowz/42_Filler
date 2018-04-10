/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrqsort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 18:09:00 by zweng             #+#    #+#             */
/*   Updated: 2018/03/10 19:42:10 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

static int	artition(t_array *arr, int start, int end, int (*cmp)
			(t_arritem *, t_arritem *))
{
	t_arritem	*pivot;
	int			i;
	int			j;

	pivot = ft_arritem_at(arr, start);
	i = start;
	j = end;
	while (1)
	{
		while (cmp(pivot, ft_arritem_at(arr, i)) >= 0 && i < end)
			i++;
		while (cmp(ft_arritem_at(arr, j), pivot) > 0 && j > start)
			j--;
		if (i >= j)
			break ;
		ft_arrswap(arr, i, j);
	}
	ft_arrswap(arr, start, j);
	return (j);
}

static void	pf_qsort(t_array *arr, int start, int end, int (*cmp)
			(t_arritem *, t_arritem *))
{
	int		j;

	if (!arr || !(arr->table))
		return ;
	if (start < end)
	{
		j = artition(arr, start, end, cmp);
		pf_qsort(arr, start, j - 1, cmp);
		pf_qsort(arr, j + 1, end, cmp);
	}
}

void		ft_arrqsort(t_array *arr, int (*cmp)(t_arritem *,
			t_arritem *))
{
	if (!arr || !cmp || arr->current_size <= 1)
		return ;
	pf_qsort(arr, 0, arr->current_size - 1, cmp);
}
