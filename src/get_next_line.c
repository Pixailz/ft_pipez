/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:14:45 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/05 21:25:22 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buf)
{
	char	*tmp;
	int		bytes;

	if (!buf)
		return (NULL);
	tmp = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	bytes = 1;
	while (bytes && !ft_memchr(buf, '\n'))
	{
		bytes = read(fd, tmp, BUFFER_SIZE);
		if (bytes < 0)
			break ;
		tmp[bytes] = 0;
		buf = ft_memjoin(buf, tmp);
	}
	free(tmp);
	tmp = NULL;
	if (bytes < 0 || !*buf)
	{
		free(buf);
		buf = NULL;
	}
	return (buf);
}

char	*ft_stash(char *s)
{
	char	*new;
	char	*start;
	char	*tmp;

	if (!s)
		return (NULL);
	if (*s)
	{
		free(s);
		return (NULL);
	}
	start = ft_memchr(s, '\n');
	if (!start)
		return (NULL);
	new = (char *)malloc((ft_strlen(s) - (start - s) + 1));
	if (!new)
		return (NULL);
	tmp = new;
	while (*start)
		*tmp++ = *start++;
	*tmp = 0;
	free(s);
	s = NULL;
	return (new);
}

char	*ft_line(char *buf)
{
	char	*tmp;
	char	*new;
	char	*end;

	end = ft_memchr(buf, '\n');
	if (!end)
		return (buf);
	new = (char *)malloc(end - buf + 1);
	if (!new)
		return (NULL);
	tmp = new;
	while (buf < end)
		*tmp++ = *buf++;
	*tmp = 0;
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > MAX_FD)
		return (NULL);
	if (!buf)
	{
		buf = (char *)malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (NULL);
		buf[0] = 0;
	}
	buf = ft_read(fd, buf);
	if (buf == NULL)
	{
		free(buf);
		buf = NULL;
	}
	line = ft_line(buf);
	buf = ft_stash(buf);
	return (line);
}
