/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:17:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/21 01:22:18 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

#include <stdio.h>

void	init_pipex(t_pipex *pipex, char **argv, char **envp)
{
	pipex->envp = envp;
	pipex->path = get_path(envp);
	pipex->cmd_success = 0;
	pipex->cmd1 = get_command(pipex, argv[2]);
	pipex->cmd2 = get_command(pipex, argv[3]);
	pipe(pipex->end);
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		free_pipex(pipex);
		ft_error(argv[1]);
	}
	pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
}
