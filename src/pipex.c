/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:02:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/05 15:40:09 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	pipex = malloc(sizeof(t_pipex));
	if (argc < 5)
	{
		free(pipex);
		return (ft_error("Wrong args"));
	}
	pipex->cmd_nb = argc - 3;
	pipex->cmd_success = 0;
	init_pipex(pipex, argv, envp);
	pipex->pidid = 0;
	while (pipex->pidid < pipex->cmd_nb)
		do_command(pipex);
	free_pipex(pipex);
	return (0);
}
