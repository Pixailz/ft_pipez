/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:08:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/28 18:09:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strdup(const char *s)
{
	char	*tmp;
	char	*ptr;

	tmp = (char *)s;
	while (*tmp)
		tmp++;
	ptr = (char *)malloc((tmp - s) + 1);
	tmp = ptr;
	while (*s && tmp)
		*tmp++ = *s++;
	if (ptr)
		*tmp = 0;
	return (ptr);
}
