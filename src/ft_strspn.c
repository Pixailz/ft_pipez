/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:28:24 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/27 17:28:34 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

size_t	ft_strspn(char *s, const char *accepts)
{
	size_t	i;

	i = 0;
	while (s[i] && ft_strchr(accepts, s[i]))
		i++;
	return (i);
}
