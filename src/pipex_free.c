/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:19:43 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/21 01:14:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_command(t_cmd *cmd)
{
	free(cmd->cmd_str);
	cmd->cmd_str = NULL;
	free(cmd->cmd_path);
	cmd->cmd_path = NULL;
	free(cmd);
	cmd = NULL;
}

void	free_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_success - 1)
	{
		close(pipex->pipe[i][0]);
		close(pipex->pipe[i][1]);
		free(pipex->pipe[i]);
		i++;
	}
	free(pipex->pipe);
}

void	free_pipex(t_pipex *pipex)
{
	size_t	i;

	if (pipex->here_doc)
		unlink(".heredoc_tmp");
	i = 0;
	while (i < (size_t)pipex->cmd_success)
		free_command(pipex->cmd[i++]);
	free(pipex->cmd);
	i = 0;
	while (pipex->path[i])
	{
		free(pipex->path[i]);
		pipex->path[i] = NULL;
		i++;
	}
	free(pipex->path);
	free_pipes(pipex);
	pipex->path = NULL;
	free(pipex);
	pipex = NULL;
}

void	free_unfinished(t_pipex *pipex, t_cmd *cmd)
{
	size_t	i;

	i = 0;
	while (i < (size_t)pipex->cmd_success)
		free_command(pipex->cmd[i++]);
	free(pipex->cmd);
	i = 0;
	while (pipex->path[i])
	{
		free(pipex->path[i]);
		pipex->path[i] = NULL;
		i++;
	}
	free(pipex->path);
	if (pipex->cmd_success == pipex->cmd_nb)
		free_pipes(pipex);
	else
		free(pipex->pipe);
	pipex->path = NULL;
	free(pipex);
	pipex = NULL;
	free_command(cmd);
}

void	close_pipex(t_pipex *pipex)
{
	free_pipex(pipex);
}
