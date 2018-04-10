/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:35:14 by zweng             #+#    #+#             */
/*   Updated: 2018/03/07 19:57:06 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_wchar.h"
#include "ft_rpstr.h"

size_t			ft_wstrlen(const wchar_t *wstr)
{
	const wchar_t	*ptr;

	ptr = wstr;
	while (*ptr)
		ptr++;
	return ((size_t)(ptr - wstr));
}

size_t			ft_widetoa(char *buf, wint_t w)
{
	char	*ptr;

	ptr = buf;
	if (w < 0x100)
		*buf++ = (w & 0xff);
	else if (w < 0x800)
	{
		*(buf++) = ((w >> 6) & 0x1F) | 0xC0;
		*(buf++) = ((w >> 0) & 0x3F) | 0x80;
	}
	else if (w < 0x10000)
	{
		*(buf++) = ((w >> 12) & 0xF) | 0xE0;
		*(buf++) = ((w >> 6) & 0x3F) | 0x80;
		*(buf++) = ((w >> 0) & 0x3F) | 0x80;
	}
	else if (w < 0x110000)
	{
		*(buf++) = ((w >> 18) & 0x7) | 0xF0;
		*(buf++) = ((w >> 12) & 0x3F) | 0x80;
		*(buf++) = ((w >> 6) & 0x3F) | 0x80;
		*(buf++) = ((w >> 0) & 0x3F) | 0x80;
	}
	return (buf - ptr);
}

char			*ft_wstrtomb(const wchar_t *wstr)
{
	char	*ret;
	size_t	i;

	i = 0;
	if (!(ret = ft_strnew(ft_wstrlen(wstr) * 4)))
		return (NULL);
	while (*wstr)
		i += ft_widetoa(ret + i, (wint_t)*(wstr++));
	return (ret);
}

static size_t	pf_get_wstrn(char **buf, const wchar_t *wstr, size_t size)
{
	size_t	ret;
	size_t	tmp;
	char	*tmp_str;

	ret = 0;
	tmp = 0;
	if (!(tmp_str = ft_strnew(4 * ft_wstrlen(wstr))))
		return (ret);
	while (*wstr)
	{
		tmp = ft_widetoa(tmp_str + ret, (wint_t)*(wstr++));
		if (tmp + ret > size)
			break ;
		ret += tmp;
	}
	if (!(*buf = ft_strnew(ret)))
		return (0);
	ft_memcpy(*buf, tmp_str, ret);
	ft_strdel(&tmp_str);
	return (ret);
}

size_t			ft_wstrntomb(char **buf, const wchar_t *wstr, size_t size)
{
	size_t	ret;

	if (wstr == 0)
	{
		if ((int)size == -1)
			*buf = ft_strdup("(null)");
		else
			*buf = ft_strndup("(null)", size);
		return (ft_strlen(*buf));
	}
	if ((int)size == -1)
	{
		*buf = ft_wstrtomb(wstr);
		ret = (ft_strlen(*buf));
	}
	else
	{
		ret = pf_get_wstrn(buf, wstr, size);
	}
	return (ret);
}
