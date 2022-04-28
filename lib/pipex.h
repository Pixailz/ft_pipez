/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 03:51:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/28 20:33:41 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// LIBRARY
# include "utils.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

// STRUCT
typedef struct s_cmd
{
	char	*cmd;
	char	*cmd_path;
	char	**cmd_arg;
	size_t	size;
}t_cmd;

typedef struct s_pipex
{
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	char	**path;
}t_pipex;

// CONFIG

// MAIN

// UTILS
int		ft_perror(char *msg);
char	**get_path(char **env);
void	free_pipex(t_pipex *pipex);

#endif
