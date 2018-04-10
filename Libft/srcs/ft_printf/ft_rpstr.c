/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rpstr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:53:31 by zweng             #+#    #+#             */
/*   Updated: 2018/03/07 19:54:06 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"
#include "ft_rpstr.h"

static char		*ft_handle_type_uint(t_formatph forma, va_list ap)
{
	char		*ret;
	uintmax_t	val;

	ret = 0;
	if (forma.length == PFLT_HH)
		val = (unsigned char)va_arg(ap, int);
	else if (forma.length == PFLT_H)
		val = (unsigned short)va_arg(ap, int);
	else if (forma.length == PFLT_LL)
		val = va_arg(ap, unsigned long long int);
	else if (forma.length == PFLT_J)
		val = va_arg(ap, uintmax_t);
	else if (forma.length == PFLT_Z)
		val = va_arg(ap, size_t);
	else if (forma.length == PFLT_L || forma.type == PFTP_CO || forma.type ==
			PFTP_CU)
		val = va_arg(ap, unsigned long int);
	else
		val = va_arg(ap, unsigned int);
	if (!(ret = pf_itoa_base(val, forma)))
		return (NULL);
	return (ft_handle_format_uint(ret, forma));
}

static char		*ft_handle_type_int(t_formatph forma, va_list ap)
{
	char		*ret;
	intmax_t	val;

	ret = 0;
	if (forma.length == PFLT_HH)
		val = (char)va_arg(ap, int);
	else if (forma.length == PFLT_H)
		val = (short)va_arg(ap, int);
	else if (forma.length == PFLT_LL)
		val = va_arg(ap, long long int);
	else if (forma.length == PFLT_L || forma.type == PFTP_CD)
		val = va_arg(ap, long int);
	else if (forma.length == PFLT_J)
		val = va_arg(ap, intmax_t);
	else if (forma.length == PFLT_Z)
		val = va_arg(ap, ssize_t);
	else
		val = va_arg(ap, int);
	if (!(ret = pf_itoa_base(val, forma)))
		return (NULL);
	return (ft_handle_format_int(ret, val, forma));
}

static char		*ft_handle_charstr(t_formatph forma, va_list ap, size_t *n)
{
	char		*ret;
	size_t		size;

	ret = 0;
	size = 0;
	if (forma.type == PFTP_CC || (forma.type == PFTP_C &&
				forma.length == PFLT_L))
	{
		if ((ret = ft_strnew(4)))
			size = ft_widetoa(ret, va_arg(ap, wint_t));
		*n = forma.fieldwidth > (int)size ? forma.fieldwidth : size;
	}
	else if (forma.type == PFTP_C)
	{
		if ((ret = pf_handle_null_c(va_arg(ap, unsigned int))))
			size = 1;
		*n = forma.fieldwidth > 1 ? forma.fieldwidth : 1;
	}
	else if (forma.type == PFTP_CS || (forma.type == PFTP_S &&
				forma.length == PFLT_L))
		size = ft_wstrntomb(&ret, va_arg(ap, wchar_t *), forma.precision);
	else
		size = pf_handle_null_str(&ret, va_arg(ap, char *), forma.precision);
	return (ft_handle_format_charstr(ret, size, forma));
}

static char		*ft_handle_p_pc(t_formatph forma, va_list ap)
{
	char		*ret;

	ret = 0;
	if (forma.type == PFTP_P)
	{
		if ((forma.flags & PFFL_HT) == 0)
		{
			forma.length = PFLT_L;
			forma.flags += PFFL_HT;
		}
		ret = ft_handle_type_uint(forma, ap);
	}
	else
	{
		if (!(ret = ft_strnew(1)))
			return (NULL);
		else if (forma.type > PFTP_N)
			*ret = forma.type - PFTP_PC;
		else
			*ret = '%';
		if (forma.fieldwidth > 1)
			ret = pf_padding(ret, 1, forma);
	}
	return (ret);
}

size_t			ft_rpstr(char **buf, t_formatph forma, va_list ap)
{
	char		*ret;
	size_t		size;

	size = 0;
	ret = 0;
	if (forma.type == PFTP_D || forma.type == PFTP_I || forma.type == PFTP_CD)
		ret = ft_handle_type_int(forma, ap);
	else if (forma.type >= PFTP_O && forma.type <= PFTP_CX)
		ret = ft_handle_type_uint(forma, ap);
	else if (forma.type == PFTP_S || forma.type == PFTP_CS ||
			forma.type == PFTP_C || forma.type == PFTP_CC)
		ret = ft_handle_charstr(forma, ap, &size);
	else
		ret = ft_handle_p_pc(forma, ap);
	if (!ret)
		return (0);
	*buf = ret;
	if (forma.type != PFTP_C && forma.type != PFTP_CC)
		size = ft_strlen(ret);
	return (size);
}
