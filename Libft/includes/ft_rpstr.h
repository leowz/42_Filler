/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rpstr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 20:15:20 by zweng             #+#    #+#             */
/*   Updated: 2018/01/12 20:11:24 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RPSTR_H
# define FT_RPSTR_H

# include "ft_printf_private.h"

char	*ft_handle_format_uint(char *rawstr, t_formatph forma);
char	*ft_handle_format_int(char *rawstr, intmax_t val, t_formatph forma);
char	*ft_handle_format_charstr(char *rawstr, size_t len, t_formatph forma);
char	*pf_itoa_base(uintmax_t val, t_formatph forma);
char	*pf_add_prefix_str(char *str, const char *str_to_add);
char	*ft_strndup(char *str, size_t size);
char	*pf_padding(char *rawstr, size_t len, t_formatph forma);
char	*pf_handle_null_c(const char c);
size_t	pf_handle_null_str(char **buf, const char *str, int n);
int		pf_get_base(const t_formatph forma);
#endif
