/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:31:25 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 17:18:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_command_infile(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		dup2(pipex->pipe[0][1], 1);
		close(pipex->pipe[0][0]);
		dup2(pipex->infile, 0);
		execve(pipex->cmd[pipex->pidid]->cmd_path, \
				pipex->cmd[pipex->pidid]->cmd, \
				pipex->path);
	}
}

void	do_command_between(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		dup2(pipex->pipe[pipex->pidid - 1][0], 0);
		dup2(pipex->pipe[pipex->pidid][1], 1);
		close(pipex->pipe[pipex->pidid][0]);
		execve(pipex->cmd[pipex->pidid]->cmd_path, \
				pipex->cmd[pipex->pidid]->cmd, \
				pipex->path);
	}
}

void	do_command_outfile(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		dup2(pipex->pipe[pipex->pidid - 1][0], 0);
		close(pipex->pipe[pipex->pidid - 1][1]);
		dup2(pipex->outfile, 1);
		execve(pipex->cmd[pipex->pidid]->cmd_path, \
				pipex->cmd[pipex->pidid]->cmd, \
				pipex->path);
	}
}

void	do_command(t_pipex *pipex)
{
	if (pipex->pidid == 0)
		do_command_infile(pipex);
	else if (pipex->pidid == pipex->cmd_nb - 1)
		do_command_outfile(pipex);
	else
		do_command_between(pipex);
	pipex->pidid++;
}
