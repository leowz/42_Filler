/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:04:12 by zweng             #+#    #+#             */
/*   Updated: 2018/03/07 19:14:11 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

static void		pf_init_forma(t_formatph *forma)
{
	forma->param = 0;
	forma->flags = 0;
	forma->fieldwidth = 0;
	forma->precision = PRC_NO;
	forma->length = 0;
	forma->type = 0;
}

static void		ft_scan(const char **format, t_formatph *forma, va_list ap)
{
	const char	*ptr;

	ptr = *format;
	pf_init_forma(forma);
	while (*ptr)
	{
		if (ft_strchr(FTPF_FL, *ptr))
			ft_scanflag(format, forma);
		else if (ft_isdigit(*ptr) || *ptr == '*')
			ft_scan_width(format, forma, ap);
		else if (*ptr == '.')
			ft_scan_precision(format, forma, ap);
		else if (ft_strchr(FTPF_LH, *ptr))
			ft_scanlength(format, forma);
		else
		{
			ft_scantype(format, forma);
			return ;
		}
		ptr = *format;
	}
	forma->type = -1;
}

size_t			ft_convert(char **buf, const char **format, t_formatph *forma,
				va_list ap)
{
	if (**format == '%')
		(*format)++;
	ft_scan(format, forma, ap);
	if (forma->precision != PRC_NO && forma->precision < 0)
	{
		if (forma->type == PFTP_S || forma->type == PFTP_CS)
			forma->precision = ft_abs(forma->precision);
		else
			forma->precision = PRC_NO;
	}
	if (forma->length < 0 || forma->type < 0)
	{
		if (!(*buf = ft_strnew(0)))
			exit(1);
		return (0);
	}
	return (ft_rpstr(buf, *forma, ap));
}
