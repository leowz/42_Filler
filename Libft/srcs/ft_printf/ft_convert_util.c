/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 21:40:44 by zweng             #+#    #+#             */
/*   Updated: 2018/01/12 19:45:31 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convert.h"

void			ft_scanflag(const char **format_ptr, t_formatph *forma)
{
	const char	*ptr;

	ptr = *format_ptr;
	while (*ptr && ft_strchr(FTPF_FL, *ptr))
	{
		if (*ptr == '+' && (forma->flags & PFFL_PL) != PFFL_PL)
			forma->flags += PFFL_PL;
		else if (*ptr == '-' && (forma->flags & PFFL_MI) != PFFL_MI)
			forma->flags += PFFL_MI;
		else if (*ptr == '#' && (forma->flags & PFFL_HT) != PFFL_HT)
			forma->flags += PFFL_HT;
		else if (*ptr == '0' && (forma->flags & PFFL_ZR) != PFFL_ZR)
			forma->flags += PFFL_ZR;
		else if (*ptr == ' ' && (forma->flags & PFFL_SP) != PFFL_SP)
			forma->flags += PFFL_SP;
		ptr++;
	}
	*format_ptr = ptr;
}

void			ft_scan_width(const char **format_ptr,
		t_formatph *forma, va_list ap)
{
	const char	*ptr;
	int			tmp;

	ptr = *format_ptr;
	if (*ptr == '*')
	{
		tmp = (int)va_arg(ap, int);
		if (tmp < 0 && (forma->flags & PFFL_MI) != PFFL_MI)
			forma->flags += PFFL_MI;
		forma->fieldwidth = ft_abs(tmp);
		ptr++;
	}
	else if (ft_isdigit(*ptr))
	{
		forma->fieldwidth = ft_atoi(ptr);
		while (ft_isdigit(*ptr))
			ptr++;
	}
	*format_ptr = ptr;
}

void			ft_scan_precision(const char **format_ptr,
		t_formatph *forma, va_list ap)
{
	const char	*ptr;
	int			tmp;

	ptr = *format_ptr;
	if (*ptr == '.')
	{
		forma->precision = 0;
		ptr++;
		if (*ptr == '*')
		{
			tmp = (int)va_arg(ap, int);
			forma->precision = tmp;
		}
		else if (ft_isdigit(*ptr))
			forma->precision = ft_atoi(ptr);
		while (ft_isdigit(*ptr) || *ptr == '*')
			ptr++;
	}
	*format_ptr = ptr;
}

void			ft_scanlength(const char **format_ptr, t_formatph *forma)
{
	const char	*ptr;

	ptr = *format_ptr;
	while (*ptr && ft_strchr(FTPF_LH, *ptr))
	{
		if (forma->length != -1)
		{
			if (*ptr == 'h' && forma->length < PFLT_HH)
				forma->length += PFLT_H;
			else if (*ptr == 'l' && forma->length < PFLT_L)
				forma->length = PFLT_L;
			else if (*ptr == 'l' && forma->length == PFLT_L)
				forma->length = PFLT_LL;
			else if (*ptr == 'j' && forma->length < PFLT_J)
				forma->length = PFLT_J;
			else if (*ptr == 'z' && forma->length < PFLT_Z)
				forma->length = PFLT_Z;
		}
		ptr++;
	}
	*format_ptr = ptr;
}

void			ft_scantype(const char **format_ptr, t_formatph *forma)
{
	const char	*ptr;
	int			i;
	char		*type_str;

	type_str = " sSpdDioOuUxXcCeEfFgGaA%n";
	ptr = *format_ptr;
	i = 1;
	while (*ptr && i <= PFTP_N)
	{
		if (*ptr == type_str[i] || i == PFTP_N)
		{
			forma->type = *ptr == type_str[i] ? i : PFTP_PC + (int)*ptr;
			*format_ptr += 1;
			if (*ptr == 'D' || *ptr == 'O' || *ptr == 'U')
				forma->length = 0;
			return ;
		}
		i++;
	}
	forma->type = -1;
}
