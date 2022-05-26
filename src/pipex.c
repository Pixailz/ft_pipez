/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:02:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/26 20:35:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	have_her_doc(char *arg)
{
	if (arg && !ft_strncmp("here_doc", arg, 9))
		return (1);
	else
		return (0);
}

int	have_her_cmd(char *arg)
{
	if (arg && !ft_strncmp("here_cmd", arg, 9))
		return (1);
	else
		return (0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	pipex->here_doc = have_her_doc(argv[1]);
	pipex->here_cmd = have_her_cmd(argv[1]);
	if (argc < 5 + pipex->here_doc + pipex->here_cmd)
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
