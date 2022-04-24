/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:14:04 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/16 17:10:31 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(va_list args, const char *format)
{
	int	size;

	size = 0;
	while (*format)
	{
		if (*format == '%' && ft_checkparams(*(format + 1)))
			size += ft_sel_params(args, *(format++ + 1));
		else
			size += ft_putchar(*format);
		format++;
	}
	return (size);
}
