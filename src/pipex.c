/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:02:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 19:53:59 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	args_in(char *arg, t_pipex *pipex)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
	{
		pipex->here_doc = 1;
		return (6);
	}
	else
	{
		pipex->here_doc = 0;
		return (5);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (argc < args_in(argv[1], pipex))
	{
		free(pipex);
		return (ft_error("Not enough args"));
	}
	pipex->cmd_nb = argc - 3 - pipex->here_doc;
	pipex->cmd_success = 0;
	init_pipex(pipex, argv, envp);
	pipex->pidid = 0;
	while (pipex->pidid < pipex->cmd_nb)
		do_command(pipex);
	free_pipex(pipex);
	return (0);
}
