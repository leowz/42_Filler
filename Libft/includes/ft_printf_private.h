/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 20:00:16 by zweng             #+#    #+#             */
/*   Updated: 2018/03/04 20:05:41 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRIVATE_H
# define FT_PRINTF_PRIVATE_H

# include <stdarg.h>
# include "libft.h"
# include "ft_printf_macro.h"

# define FTPF_PA "$"
# define FTPF_FL "+- #0"
# define FTPF_TY "diouxXDOUeEfFgGaAcCsSpnb"
# define FTPF_LH "hlzjL"
# define PRC_NO (-2147483647)

typedef struct		s_formatph
{
	int				param;
	int				flags;
	int				fieldwidth;
	int				precision;
	int				length;
	int				type;
}					t_formatph;

size_t				ft_convert(char **buf, const char **format, t_formatph
					*forma, va_list ap);
size_t				ft_rpstr(char **buf, t_formatph forma, va_list ap);
#endif
