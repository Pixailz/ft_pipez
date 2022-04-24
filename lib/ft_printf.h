#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// CONFIG
# define PARAMS_LIST "cspdiuxX%"
# define HEX_UPPER "0123456789ABCDEF"
# define HEX_LOWER "0123456789abcdef"

// LIBRARY
# include "utils.h"
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

// MAIN
int	ft_printf(const char *format, ...);
int	ft_parse(va_list args, const char *format);
int	ft_checkparams(char c);
int	ft_sel_params(va_list args, char param_type);
int	ft_put_addr(va_list args);

#endif
