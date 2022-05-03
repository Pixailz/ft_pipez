/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:02:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 19:00:03 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_file(t_pipex *pipex, char **argv)
{
	pipex->infile = open(argv[1], O_RDONLY);
	if (pipex->infile < 0)
	{
		free_pipex(pipex);
		ft_error(argv[1]);
	}
	pipex->outfile = open(argv[pipex->cmd_nb + 2], \
							O_TRUNC | O_CREAT | O_RDWR, 0000644);
}

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
		pipe(pipex->pipe[i++]);
	}
	init_file(pipex, argv);
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
