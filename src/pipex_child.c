/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:31:25 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/20 22:09:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_command_infile(t_pipex *pipex)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
	{
		dup2(pipex->end[1], 1);
		close(pipex->end[0]);
		dup2(pipex->infile, 0);
		execve(pipex->cmd1->cmd_path, pipex->cmd1->cmd, pipex->path);
	}
}

void	do_command_outfile(t_pipex *pipex)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
	{
		dup2(pipex->end[0], 0);
		close(pipex->end[1]);
		dup2(pipex->outfile, 1);
		execve(pipex->cmd2->cmd_path, pipex->cmd2->cmd, pipex->path);
	}
}

void	do_command(t_pipex *pipex, int mode)
{
	if (mode == -1)
		do_command_infile(pipex);
	else if (mode == 1)
	{
		waitpid(pipex->pid1, NULL, 0);
		do_command_outfile(pipex);
	}
}
