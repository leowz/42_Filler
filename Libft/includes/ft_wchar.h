/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 17:22:22 by zweng             #+#    #+#             */
/*   Updated: 2018/01/12 20:10:56 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WCHAR_H
# define FT_WCHAR_H

# include <wchar.h>
# include "libft.h"

size_t	ft_wstrlen(const wchar_t *wstr);
size_t	ft_widetoa(char *buf, wint_t w);
char	*ft_wstrtomb(const wchar_t *wstr);
size_t	ft_wstrntomb(char **buf, const wchar_t *wstr, size_t n);
#endif
