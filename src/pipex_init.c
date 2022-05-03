/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:17:44 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 19:38:55 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	here_doc(char *limiter, t_pipex *pipex)
{
	int		file;
	char	*buf;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	while (1)
	{
		ft_putstr("heredoc>");
		if (get_next_line(1, &buf))
			exit(1);
		if (!ft_strncmp(limiter, buf, ft_strlen(limiter) + 1))
			break ;
		write(file, buf, ft_strlen(buf));
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
	if (!ft_strncmp("here_doc", argv[1], 9))
		here_doc(argv[2], pipex);
	else
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
		{
			free_pipex(pipex);
			ft_error(argv[1]);
		}
	}
	pipex->outfile = open(argv[pipex->cmd_nb + 2], \
							O_TRUNC | O_CREAT | O_RDWR, 0000644);
}

void	init_pipex(t_pipex *pipex, char **argv, char **envp)
{
	int		i;

	pipex->cmd = malloc(sizeof(t_cmd) * pipex->cmd_nb + 1);
	pipex->pipe = malloc(sizeof(int *) * pipex->cmd_nb);
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
