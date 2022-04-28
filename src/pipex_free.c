/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:19:43 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/28 20:41:44 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_pipex(t_pipex *pipex)
{
	free(pipex->cmd1->cmd);
	free(pipex->cmd1->cmd_path);
	free(pipex->cmd1->cmd_arg);
	free(pipex->cmd1);
	free(pipex->cmd2->cmd);
	free(pipex->cmd2->cmd_path);
	free(pipex->cmd2->cmd_arg);
	free(pipex->cmd2);
	free(pipex->path);
	free(pipex);
}
