/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_macro.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zweng <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 12:21:23 by zweng             #+#    #+#             */
/*   Updated: 2017/12/30 15:48:10 by zweng            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_MACRO_H
# define FT_PRINTF_MACRO_H

/*
** Macrons for printf flags
*/
# define PFFL_HT 1
# define PFFL_ZR 2
# define PFFL_MI 4
# define PFFL_PL 8
# define PFFL_SP 16
/*
** Macros for length
*/
# define PFLT_H     1
# define PFLT_HH    2
# define PFLT_L     3
# define PFLT_LL    4
# define PFLT_J     5
# define PFLT_Z     6
# define PFLT_CL    7
/*
** Macros for types
*/
# define PFTP_S     1
# define PFTP_CS    2
# define PFTP_P     3
# define PFTP_D     4
# define PFTP_CD    5
# define PFTP_I     6
# define PFTP_O     7
# define PFTP_CO    8
# define PFTP_U     9
# define PFTP_CU    10
# define PFTP_X     11
# define PFTP_CX    12
# define PFTP_C     13
# define PFTP_CC    14
# define PFTP_E     15
# define PFTP_CE    16
# define PFTP_F     17
# define PFTP_CF    18
# define PFTP_G     19
# define PFTP_CG    20
# define PFTP_A     21
# define PFTP_CA    22
# define PFTP_PC    23
# define PFTP_N     24
#endif
