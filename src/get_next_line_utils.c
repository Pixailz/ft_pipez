/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:38:46 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 03:57:39 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	char	*t;
	if (!s)
		return (0);
	t = s;
	while (*t)
		t++;
	return (t - s);
}

char	*ft_memjoin(char *s1, char *s2)
{
	char	*new;
	char	*tmp;
	char	*save;

	new = (char *)malloc(ft_len(s1) + ft_len(s2) + 1);
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

char	*ft_memchr(char *buf, unsigned char c)
{
	if (!buf)
		return (NULL);
	while (*buf && buf != c)
		buf++;
	if (!*buf)
		return (NULL);
	return (++buf);
}
