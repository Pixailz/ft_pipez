/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:02:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/02 03:09:20 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init_pipex(t_pipex *pipex, char **argv, char **envp)
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;

	pipex->path = get_path(envp);
	cmd1 = get_command(pipex, argv[2]);
	cmd2 = get_command(pipex, argv[3]);
	pipex->cmd1 = cmd1;
	pipex->cmd2 = cmd2;
	pipex->infile = open(argv[1], O_RDONLY);
	pipex->outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);
	pipe(pipex->end);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 5)
		return (ft_error("Not enough args"));
	pipex = malloc(sizeof(t_pipex));
	init_pipex(pipex, argv, envp);
	do_command(pipex, -1);
	do_command(pipex, 1);
	free_pipex(pipex);
}
// run "data.txt" "cat -e" "sed -nE 's|[0-9]*(.*)|\1|p'" "outfile.txt"
