/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sel_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:27:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 18:35:12 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sel_params(va_list args, char param_type)
{
	if (param_type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (param_type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (param_type == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (param_type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (param_type == 'u')
		return (ft_putnbr_u(va_arg(args, unsigned int)));
	else if (param_type == 'p')
		return (ft_put_addr(args));
	else if (param_type == 'x')
		return (ft_puthex(va_arg(args, unsigned int), param_type));
	else if (param_type == 'X')
		return (ft_puthex(va_arg(args, unsigned int), param_type));
	else if (param_type == '%')
		return (ft_putchar('%'));
	return (0);
}
