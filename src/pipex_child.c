/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_child.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 02:31:25 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/21 01:26:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_command_infile(t_pipex *pipex, char **cmd_arg)
{
	pipex->pid1 = fork();
	if (pipex->pid1 == 0)
	{
		dup2(pipex->end[1], 1);
		close(pipex->end[0]);
		dup2(pipex->infile, 0);
		execve(pipex->cmd1->cmd_path, cmd_arg, pipex->path);
	}
}

void	do_command_outfile(t_pipex *pipex, char **cmd_arg)
{
	pipex->pid2 = fork();
	if (pipex->pid2 == 0)
	{
		dup2(pipex->end[0], 0);
		close(pipex->end[1]);
		dup2(pipex->outfile, 1);
		execve(pipex->cmd2->cmd_path, cmd_arg, pipex->path);
	}
}

void	do_command(t_pipex *pipex, int mode)
{
	char	**cmd_arg;
	int		size_cmd;
	int		counter;

	if (mode == -1)
	{
		size_cmd = ft_get_words(pipex->cmd1->cmd_str, ' ');
		cmd_arg = ft_split(pipex->cmd1->cmd_str, ' ');
		do_command_infile(pipex, cmd_arg);
	}
	else if (mode == 1)
	{
		waitpid(pipex->pid1, NULL, 0);
		size_cmd = ft_get_words(pipex->cmd2->cmd_str, ' ');
		cmd_arg = ft_split(pipex->cmd2->cmd_str, ' ');
		do_command_outfile(pipex, cmd_arg);
	}
	counter = 0;
	while (counter < size_cmd)
		free(cmd_arg[counter++]);
	free(cmd_arg);
}
