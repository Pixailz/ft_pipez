/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 03:51:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 18:45:56 by brda-sil         ###   ########.fr       */
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
# include <sys/wait.h>
# include <errno.h>

// STRUCT
typedef struct s_cmd
{
	char	**cmd;
	char	*cmd_path;
	size_t	size;
}	t_cmd;

typedef struct s_pipex
{
	t_cmd	**cmd;
	int		cmd_nb;
	int		cmd_success;
	pid_t	pid;
	int		pidid;
	int		infile;
	int		outfile;
	int		**pipe;
	char	**path;
}	t_pipex;

// CONFIG

// MAIN

// UTILS
int		ft_error(char *msg);
char	**get_path(char **env);
t_cmd	*get_command(t_pipex *pipex, char *cmd_str);
void	get_command_arg(t_cmd *cmd, char *token);
char	*check_path(t_pipex *pipex, char *cmd_str);
void	close_pipex(t_pipex *pipex);
void	free_pipex(t_pipex *pipex);
void	free_command(t_cmd *cmd);
void	free_unfinished(t_pipex *pipex, t_cmd *cmd);
void	do_command(t_pipex *pipex);
void	do_command_outfile(t_pipex *pipex);
void	do_command_outfile(t_pipex *pipex);

#endif
