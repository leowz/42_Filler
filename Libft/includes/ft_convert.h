/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 21:42:40 by zweng             #+#    #+#             */
/*   Updated: 2018/01/12 20:10:44 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERT_H
# define FT_CONVERT_H

# include "ft_printf_private.h"

void			ft_scanflag(const char **format_ptr, t_formatph *forma);
void			ft_scan_width(const char **format_ptr,
				t_formatph *forma, va_list ap);
void			ft_scan_precision(const char **format_ptr,
				t_formatph *forma, va_list ap);
void			ft_scanlength(const char **format_ptr, t_formatph *forma);
void			ft_scantype(const char **format_ptr, t_formatph *forma);
#endif
