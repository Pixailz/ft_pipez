/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 03:51:57 by brda-sil          #+#    #+#             */
/*   Updated: 2022/08/21 00:57:50 by brda-sil         ###   ########.fr       */
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
	t_cmd	*cmd1;
	t_cmd	*cmd2;
	int		cmd_success;
	pid_t	pid1;
	pid_t	pid2;
	int		infile;
	int		outfile;
	int		end[2];
	char	**path;
	char	**envp;
}	t_pipex;

/* ########################################################################## */

/* ########################################################################## */
/* FILES */
/* ##### */

// ft_calloc.c
void	*ft_calloc(size_t nmemb, size_t size);

// ft_checkparams.c
int		ft_checkparams(char c);

// ft_error.c
int		ft_error(char *msg);

// ft_get_words.c
int		ft_get_words(char const *str, char c);

// ft_memchr.c
char	*ft_memchr(char *buf, unsigned char c);

// ft_memjoin.c
char	*ft_memjoin(char *s1, char *s2);

// ft_memset.c
void	*ft_memset(void *s, int c, size_t n);

// ft_parse.c
int		ft_parse(va_list args, const char *format);

// ft_printf.c
int		ft_printf(const char *format, ...);

// ft_put_addr.c
int		ft_put_addr(va_list args);

// ft_putchar.c
int		ft_putchar(char c);

// ft_puthex.c
int		ft_puthex(unsigned long n, char format);

// ft_putnbr.c
int		ft_putnbr(int n);

// ft_putnbr_u.c
int		ft_putnbr_u(unsigned int n);

// ft_putstr.c
int		ft_putstr(char *s);

// ft_sel_params.c
int		ft_sel_params(va_list args, char param_type);

// ft_split.c
char	**ft_split(char const *s, char c);

// ft_strcat.c
char	*ft_strcat(char *dest, const char *src);

// ft_strchr.c
char	*ft_strchr(const char *s, int c);

// ft_strcpy.c
char	*ft_strcpy(char *dest, const char *src);

// ft_strcspn.c
size_t	ft_strcspn(char *s, const char *rejects);

// ft_strdup.c
char	*ft_strdup(const char *s);

// ft_strjoin.c
char	*ft_strjoin(char const *s1, char const *s2);

// ft_strlen.c
size_t	ft_strlen(char *s);

// ft_strncmp.c
int		ft_strncmp(const char *s1, const char *s2, size_t n);

// ft_strspn.c
size_t	ft_strspn(char *s, const char *accepts);

// ft_strtok.c
char	*ft_strtok(char *str, char *token);

// get_next_line.c
char	*ft_read(int fd, char *buf);
char	*ft_stash(char *s);
char	*ft_line(char *buf);
char	*get_next_line(int fd);

// pipex_child.c
void	do_command_infile(t_pipex *pipex, char **cmd_arg);
void	do_command_outfile(t_pipex *pipex, char **cmd_arg);
void	do_command(t_pipex *pipex, int mode);

// pipex_cmd.c
char	**get_path(char **env);
char	*check_path(t_pipex *pipex, char *cmd_str);
t_cmd	*get_command(t_pipex *pipex, char *cmd_str);

// pipex_free.c
void	free_command(t_cmd *cmd);
void	free_unfinished(t_pipex *pipex, t_cmd *cmd);
void	free_pipex(t_pipex *pipex);

// pipex_init.c
void	init_pipex(t_pipex *pipex, char **argv, char **envp);

/* ########################################################################## */

#endif
