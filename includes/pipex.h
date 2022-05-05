/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 03:51:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/05 02:03:29 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
/* ########################################################################## */
/* CONFIG */
/* ###### */

# define VRAI 1

/* ########################################################################## */

/* ########################################################################## */
/* INCLUDE */
/* ####### */

# include "utils.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

/* ########################################################################## */

/* ########################################################################## */
/* STRUCT */
/* ###### */

typedef struct s_cmd
{
	char	*cmd_str;
	char	*cmd_path;
}	t_cmd;

typedef struct s_pipex
{
	t_cmd	**cmd;
	int		cmd_nb;
	int		cmd_success;
	int		here_doc;
	int		here_cmd;
	pid_t	pid;
	int		pidid;
	int		infile;
	int		outfile;
	int		**pipe;
	char	**path;
}	t_pipex;

/* ########################################################################## */

/* ########################################################################## */
/* pipex.c */
/* ####### */

int		have_her_doc(char *arg);

/* ########################################################################## */

/* ########################################################################## */
/* pipex_init.c */
/* ############ */

void	init_file(t_pipex *pipex, char **argv);
void	init_pipex(t_pipex *pipex, char **argv, char **envp);
void	here_doc(char *limiter, t_pipex *pipex);

/* ########################################################################## */

/* ########################################################################## */
/* pipex_free.c */
/* ############ */

void	close_pipex(t_pipex *pipex);
void	free_unfinished(t_pipex *pipex, t_cmd *cmd);
void	free_pipex(t_pipex *pipex);
void	free_pipes(t_pipex *pipex);
void	free_command(t_cmd *cmd);

/* ########################################################################## */

/* ########################################################################## */
/* pipex_cmd.c */
/* ########### */

t_cmd	*get_command(t_pipex *pipex, char *cmd_str);
char	*check_path(t_pipex *pipex, char *cmd_str);
char	**get_path(char **env);

/* ########################################################################## */

/* ########################################################################## */
/* pipex_child.c */
/* ############# */

void	do_command(t_pipex *pipex);
void	do_command_infile(t_pipex *pipex, char **cmd_arg);
void	do_command_begin(t_pipex *pipex, char **cmd_arg);
void	do_command_between(t_pipex *pipex, char **cmd_arg);
void	do_command_outfile(t_pipex *pipex, char **cmd_arg);

/* ########################################################################## */

#endif
