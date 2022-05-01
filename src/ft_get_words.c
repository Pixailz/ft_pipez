/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 17:58:46 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/27 17:59:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_get_words(char const *str, char c)
{
	char	*tstr;
	int		count;

	tstr = (char *)str;
	count = 0;
	while (*tstr)
	{
		while (*tstr && *tstr == c)
			tstr++;
		if (*tstr && *tstr != c)
			count++;
		while (*tstr && *tstr != c)
			tstr++;
	}
	return (count);
}
