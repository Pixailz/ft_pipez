/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:02:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 13:31:46 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, char **argv, char **envp)
{
	int		i;

	i = 0;
	pipex->cmd = malloc(sizeof(t_cmd) * pipex->cmd_nb + 1);
	pipex->path = get_path(envp);
	while (i < pipex->cmd_nb)
	{
		pipex->cmd[i] = get_command(pipex, argv[2 + i]);
		i++;
	}
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[pipex->cmd_nb + 2], \
							O_TRUNC | O_CREAT | O_RDWR, 0000644);
	pipe(pipex->end);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (ft_error("Not enough args"));
	pipex = malloc(sizeof(t_pipex));
	pipex->cmd_nb = argc - 3;
	init_pipex(pipex, argv, envp);
	do_command(pipex, -1);
	do_command(pipex, 1);
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
