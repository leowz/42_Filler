/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:09:33 by zweng             #+#    #+#             */
/*   Updated: 2018/01/12 20:10:11 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_asprintf(char **buf, const char *format, ...);
int					ft_vdprintf(int fd, const char *format, va_list ap);
int					ft_vasprintf(char **s, const char *format, va_list ap);
#endif
