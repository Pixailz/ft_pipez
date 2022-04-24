/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:25:42 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 18:34:05 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_u(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n > 4294967295U)
		return (0);
	if (n >= 10)
		i += ft_putnbr_u(n / 10);
	i += ft_putchar((n % 10) + '0');
	return (i);
}
