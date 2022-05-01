/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:57:43 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/28 16:04:25 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*token;
	size_t	size;

	if (!*s)
		return (NULL);
	size = ft_get_words((char *)s, c) + 1;
	tab = (char **)malloc(sizeof(char *) * size);
	size = 0;
	token = ft_strtok((char *)s, &c);
	while (token)
	{
		tab[size] = (char *)malloc(sizeof(char) * ft_strlen(token) + 1);
		ft_strcpy(tab[size], token);
		token = ft_strtok(NULL, &c);
		size++;
	}
	tab[size] = NULL;
	return (tab);
}
