/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rpstr_util2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 21:50:40 by zweng             #+#    #+#             */
/*   Updated: 2018/03/07 19:52:18 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_rpstr.h"

char		*pf_add_prefix_str(char *str, const char *str_to_add)
{
	char	*ret;

	ret = ft_strjoin(str_to_add, str);
	ft_strdel(&str);
	return (ret);
}

char		*ft_strndup(char *str, size_t size)
{
	char	*ret;
	char	*tmp;

	ret = ft_strdup(str);
	if (ft_strlen(str) < size)
		return (ret);
	if (!(tmp = ft_strnew(size)))
		return (NULL);
	ft_memcpy(tmp, ret, size);
	ft_strdel(&ret);
	return (tmp);
}

char		*pf_handle_null_c(const char c)
{
	char	*ret;

	if (!(ret = ft_strnew(1)))
		return (NULL);
	*ret = c;
	return (ret);
}

size_t		pf_handle_null_str(char **buf, const char *str, int n)
{
	size_t	ret;

	ret = 0;
	if (n == -1)
	{
		if (str == 0)
			*buf = ft_strdup("(null)");
		else
			*buf = ft_strdup((char *)str);
		if (*buf)
			ret = ft_strlen(*buf);
	}
	else
	{
		if (str == 0)
			*buf = ft_strndup("(null)", n);
		else
			*buf = ft_strndup((char *)str, n);
		if (*buf)
			ret = ft_strlen(*buf);
	}
	if (n == PRC_NO)
		return (ret);
	return ((int)ret < n ? ret : n);
}

int			pf_get_base(const t_formatph forma)
{
	int		base;

	base = 10;
	if (forma.type == PFTP_O || forma.type == PFTP_CO)
		base = 8;
	if (forma.type == PFTP_X || forma.type == PFTP_CX || forma.type == PFTP_P)
		base = 16;
	return (base);
}
