/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:02:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 17:50:51 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, char **argv, char **envp)
{
	int		i;

	pipex->cmd = malloc(sizeof(t_cmd) * pipex->cmd_nb + 1);
	pipex->pipe = malloc(sizeof(int *) * pipex->cmd_nb);
	pipex->path = get_path(envp);
	i = 0;
	while (i < pipex->cmd_nb)
	{
		pipex->cmd[i] = get_command(pipex, argv[2 + i]);
		pipex->cmd_success++;
		i++;
	}
	i = 0;
	while (i < pipex->cmd_nb - 1)
	{
		pipex->pipe[i] = malloc(sizeof(int) * 2);
		pipe(pipex->pipe[i]);
		i++;
	}
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[pipex->cmd_nb + 2], \
							O_TRUNC | O_CREAT | O_RDWR, 0000644);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (ft_error("Not enough args"));
	pipex = malloc(sizeof(t_pipex));
	pipex->cmd_nb = argc - 3;
	pipex->cmd_success = 0;
	init_pipex(pipex, argv, envp);
	pipex->pidid = 0;
	while (pipex->pidid < pipex->cmd_nb)
		do_command(pipex);
	free_pipex(pipex);
	return (0);
}

/*
int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (ft_error("Not enough args"));
	pipex = malloc(sizeof(t_pipex));
	pipex->cmd_nb = argc - 3;
	init_pipex(pipex, argv, envp);
	pipe(pipex->end);
	pipe(pipex->end2);
	pipex->pid = fork ();
	if (pipex->pid == 0)
	{
		dup2(pipex->end[1], 1);
		close(pipex->end[0]);
		dup2(pipex->infile, 0);
		execve(pipex->cmd[0]->cmd_path, pipex->cmd[0]->cmd, pipex->path);
	}
	pipex->pid = fork ();
	if (pipex->pid == 0)
	{
		dup2(pipex->end[0], 0);
		dup2(pipex->end2[1], 1);
		close(pipex->end2[0]);
		execve(pipex->cmd[1]->cmd_path, pipex->cmd[1]->cmd, pipex->path);
	}
	pipex->pid = fork ();
	if (pipex->pid == 0)
	{
		dup2(pipex->end2[0], 0);
		close(pipex->end2[1]);
		dup2(pipex->outfile, 1);
		execve(pipex->cmd[pipex->cmd_nb - 1]->cmd_path, \
				pipex->cmd[pipex->cmd_nb - 1]->cmd, \
				pipex->path);
	}
	free_pipex(pipex);
	return (0);
}
*/
// run "data.txt" "cat -e" "sed -nE 's|[0-9]*(.*)|\1|p'" "outfile.txt"
