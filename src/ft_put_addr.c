/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:56:22 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 18:15:52 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_addr(va_list args)
{
	unsigned long long	addr;

	addr = va_arg(args, unsigned long long);
	if (!addr)
		return (ft_putstr("(nil)"));
	return (ft_putstr("0x") + ft_puthex(addr, 'x'));
}
