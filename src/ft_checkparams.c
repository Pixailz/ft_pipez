/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkparams.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:20:06 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 18:15:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checkparams(char c)
{
	char	*t;

	t = PARAMS_LIST;
	while (*t)
		if (c == *t++)
			return (1);
	return (0);
}
