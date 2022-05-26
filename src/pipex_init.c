/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:17:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/26 22:39:35 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *limiter, t_pipex *pipex)
{
	int		file;
	char	*buf;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	while (VRAI)
	{
		ft_putstr("heredoc> ");
		buf = get_next_line(1);
		if (!buf)
			exit(1);
		if (buf[ft_strlen(limiter)] == '\n' && \
		!ft_strncmp(limiter, buf, ft_strlen(limiter)))
			break ;
		write(file, buf, ft_strlen(buf) - 1);
		write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(file);
	pipex->infile = open(".heredoc_tmp", O_RDONLY);
	if (pipex->infile < 0)
	{
		unlink(".heredoc_tmp");
		ft_error(".heredoc_tmp");
	}
}

void	init_file(t_pipex *pipex, char **argv)
{
	if (pipex->here_doc)
	{
		here_doc(argv[2], pipex);
		pipex->outfile = open(argv[pipex->cmd_nb + 2 + pipex->here_doc], \
								O_WRONLY | O_CREAT | O_APPEND, 0000644);
	}
	else
	{
		if (!pipex->here_cmd)
		{
			pipex->infile = open(argv[1], O_RDONLY);
			if (pipex->infile < 0)
			{
				free_pipex(pipex);
				ft_error(argv[1]);
			}
		}
		pipex->outfile = open(argv[pipex->cmd_nb + 2], \
								O_CREAT | O_RDWR | O_TRUNC, 0000644);
	}
}

void	init_pipex(t_pipex *pipex, char **argv, char **envp)
{
	int		i;

	pipex->cmd = malloc(sizeof(t_cmd) * pipex->cmd_nb + 1);
	pipex->pipe = malloc(sizeof(int *) * pipex->cmd_nb);
	pipex->envp = envp;
	pipex->path = get_path(envp);
	i = 0;
	while (i < pipex->cmd_nb)
	{
		pipex->cmd[i] = get_command(pipex, argv[2 + i + pipex->here_doc]);
		pipex->cmd_success++;
		i++;
	}
	i = 0;
	while (i < pipex->cmd_nb - 1)
	{
		pipex->pipe[i] = malloc(sizeof(int) * 2);
		pipe(pipex->pipe[i++]);
	}
	init_file(pipex, argv);
}
// "here_cmd" "ls -la" "cat -e" "cat -e" {}
