/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 16:16:37 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 23:39:16 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/* ########################################################################## */
/* CONFIG */
/* ###### */

# define PARAMS_LIST "cspdiuxX%"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

/* ########################################################################## */

/* ########################################################################## */
/* LIBRARY */
/* ####### */

# include "utils.h"
# include <stdarg.h>
# include <limits.h>

/* ########################################################################## */

/* ########################################################################## */
/* FT_PRINTF */
/* ######### */

int	ft_printf(const char *format, ...);
int	ft_parse(va_list args, const char *format);
int	ft_checkparams(char c);
int	ft_sel_params(va_list args, char param_type);
int	ft_put_addr(va_list args);

/* ########################################################################## */

#endif
