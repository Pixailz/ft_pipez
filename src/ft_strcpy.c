/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:12:26 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/27 19:12:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*tmp;
	char	*tsrc;

	tmp = dest;
	tsrc = (char *)src;
	while (*tsrc)
		*tmp++ = *tsrc++;
	*tmp = 0;
	return (dest);
}
