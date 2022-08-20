/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:57:43 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/04 19:59:58 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*token;
	char	cc[2];
	size_t	size;

	if (!*s)
		return (NULL);
	size = ft_get_words((char *)s, c) + 1;
	tab = (char **)malloc(sizeof(char *) * size);
	size = 0;
	cc[0] = c;
	cc[1] = 0;
	token = ft_strtok((char *)s, cc);
	while (token)
	{
		tab[size] = (char *)malloc(sizeof(char) * ft_strlen(token) + 1);
		ft_strcpy(tab[size], token);
		token = ft_strtok(NULL, cc);
		size++;
	}
	tab[size] = NULL;
	return (tab);
}
