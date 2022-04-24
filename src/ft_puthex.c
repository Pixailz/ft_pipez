/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:12:51 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 18:22:15 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long n, char format)
{
	int				size;
	unsigned int	flag;
	unsigned int	n2;

	flag = 0;
	n2 = 0;
	size = 0;
	if (!n)
		return (ft_putchar('0'));
	if (format == 'X')
		flag = 0x20;
	if (n > 0xf)
		size += ft_puthex(n >> 0x4, format);
	n2 = n & 0xf;
	if (n2 >= 10)
		size += ft_putchar(((n2 - 10) + 'a') ^ flag);
	else if (n2 < 10)
		size += ft_putchar(n2 + '0');
	return (size);
}
/* {
	static unsigned int	size;
	unsigned int		nib;
	unsigned int		flag;

	nib = 0;
	size = 0;
	flag = 0;
	if (format == 'X')
		flag = 0x20;
	if (n == 0)
		return (ft_putchar('0'));
	if (n > 0xF)
		ft_puthex(n >> 0x4, format);
	nib = (n & 0xF);
	if (nib >= 10)
		size += ft_putchar(((nib - 10) + 'a') ^ flag);
	if (nib < 10)
		size += ft_putchar((nib + '0'));
	return (size);
} */
