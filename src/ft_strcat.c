/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:13:41 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/27 19:13:48 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*tmp;
	char	*tsrc;

	tmp = dest;
	tsrc = (char *)src;
	while (*tmp)
		tmp++;
	while (*tsrc)
		*tmp++ = *tsrc++;
	*tmp = 0;
	return (dest);
}
