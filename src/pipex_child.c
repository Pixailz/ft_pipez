/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:31:25 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/04 00:17:41 by brda-sil         ###   ########.fr       */
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
	close(pipex->pipe[0][1]);
	close(pipex->infile);
}

void	do_command_begin(t_pipex *pipex)
{
	pipex->pid = fork();
	if (pipex->pid == 0)
	{
		dup2(pipex->pipe[0][1], 1);
		dup2(pipex->pipe[0][0], 0);
		execve(pipex->cmd[pipex->pidid]->cmd_path, \
				pipex->cmd[pipex->pidid]->cmd, \
				pipex->path);
	}
	close(pipex->pipe[0][1]);
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
	close(pipex->pipe[pipex->pidid - 1][0]);
	close(pipex->pipe[pipex->pidid][1]);
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
	close(pipex->pipe[pipex->pidid - 1][0]);
	close(pipex->outfile);
}

void	do_command(t_pipex *pipex)
{
	if (pipex->pidid == 0)
	{
		if (pipex->here_cmd)
			do_command_begin(pipex);
		else
			do_command_infile(pipex);
	}
	else if (pipex->pidid == pipex->cmd_nb - 1)
		do_command_outfile(pipex);
	else
		do_command_between(pipex);
	waitpid(pipex->pid, NULL, 0);
	pipex->pidid++;
}
