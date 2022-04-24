/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:02:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/23 21:01:56 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*read_file(char *filename)
{
	int		fd;
	char	*line;
	char	*file;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	file = ft_calloc(1, sizeof(char) * ft_strlen(line));

	file = ft_memcpy(file, line, ft_strlen(line));
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			file = ft_memjoin(file, line);
	}
	return (file);
}

int	main(int argc, char **argv)
{
	char	*file;

	if (argc < 2)
		return (-1);
	file = read_file(argv[1]);
	if (!file)
		return (-1);
	printf("file : >%s<", file);
	return (0);
}
