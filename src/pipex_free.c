/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:19:43 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/21 01:21:05 by brda-sil         ###   ########.fr       */
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

void	free_unfinished(t_pipex *pipex, t_cmd *cmd)
{
	size_t	i;

	if (pipex->cmd_success == 1)
		free_command(pipex->cmd1);
	i = 0;
	while (pipex->path[i])
	{
		free(pipex->path[i]);
		pipex->path[i] = NULL;
		i++;
	}
	free(pipex->path);
	pipex->path = NULL;
	free(pipex);
	pipex = NULL;
	free_command(cmd);
}

void	free_pipex(t_pipex *pipex)
{
	size_t	i;

	free_command(pipex->cmd1);
	free_command(pipex->cmd2);
	i = 0;
	while (pipex->path[i])
	{
		free(pipex->path[i]);
		pipex->path[i] = NULL;
		i++;
	}
	free(pipex->path);
	pipex->path = NULL;
	if (pipex->infile >= 0)
	{
		close(pipex->infile);
		if (pipex->outfile >= 0)
			close(pipex->outfile);
	}
	close (pipex->end[0]);
	close (pipex->end[1]);
	free(pipex);
	pipex = NULL;
}
