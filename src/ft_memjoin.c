/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:48:53 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 17:56:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_memjoin(char *s1, char *s2)
{
	char	*new;
	char	*tmp;
	char	*save;

	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	*new = 0;
	save = new;
	tmp = s1;
	while (*tmp)
		*new++ = *tmp++;
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	while (new && *s2)
		*new++ = *s2++;
	*new = 0;
	return (save);
}
