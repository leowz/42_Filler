/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 19:32:02 by zweng             #+#    #+#             */
/*   Updated: 2018/03/10 20:23:56 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include "libft.h"
# define ARRAY_SIZE	(20)

typedef struct	s_arritem
{
	size_t		content_size;
	void		*content;
}				t_arritem;

typedef struct	s_array
{
	size_t		current_size;
	size_t		max_size;
	t_arritem	*table;
}				t_array;

/*
** t_array functions
*/
t_array			*ft_arrnew(void);
t_array			*ft_arrnew_size(size_t size);
t_array			*ft_arrnew_arr(t_array *arr);
int				ft_arrappend(t_array *arr, const t_arritem *item);
int				ft_arrappend_raw(t_array *arr, void *data, size_t size);
int				ft_arr_realloc(t_array *arr);
int				ft_arrinsert(t_array *arr, const t_arritem *item, int index);
int				ft_arrinsert_raw(t_array *arr, void *data, size_t size,
				int index);
int				ft_arrswap(t_array *arr, int index1, int index2);
t_arritem		*ft_arrremove_at(t_array *arr, int index);
t_arritem		*ft_arritem_at(t_array *arr, int index);
t_array			*ft_arrsub(t_array *arr, int start, int end);
void			ft_arrdel(t_array **arr);
/*
** t_arritem functions
*/
t_arritem		ft_arritem_new(void *data, size_t size);
void			ft_arritem_del(t_arritem *item);
/*
** stack queue functions
*/
int				ft_arrstack_push(t_array *stack, t_arritem *item);
t_arritem		*ft_arrstack_pop(t_array *stack);
t_arritem		*ft_arrstack_peek(t_array *stack);
int				ft_arrqueue_push(t_array *queue, t_arritem *item);
t_arritem		*ft_arrqueue_pop(t_array *queue);
t_arritem		*ft_arrqueue_peek(t_array *queue);
/*
** t_array util functions
*/
void			ft_arrqsort(t_array *arr, int (*cmp)(t_arritem *lhs,
				t_arritem *rhs));
void			ft_arrmsort(t_array *arr, int (*cmp)(t_arritem *lhs,
				t_arritem *rhs));
#endif
