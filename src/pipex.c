/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:02:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/21 00:04:40 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;

	if (argc < 2)
		return (ft_error("Not enough args"));
	if (argc > 5)
		return (ft_error("Too many args"));
	pipex = malloc(sizeof(t_pipex));
	init_pipex(pipex, argv, envp);
	do_command(pipex, -1);
	do_command(pipex, 1);
	free_pipex(pipex);
	return (0);
}
