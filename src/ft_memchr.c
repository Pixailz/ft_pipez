/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:49:36 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 17:56:21 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_memchr(char *buf, unsigned char c)
{
	if (!buf)
		return (NULL);
	while (*buf && *buf != c)
		buf++;
	if (!*buf)
		return (NULL);
	return (++buf);
}
