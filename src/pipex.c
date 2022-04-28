/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:02:50 by brda-sil          #+#    #+#             */
/*   Updated: 2022/04/28 20:46:00 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_perror(char *msg)
{
	return (printf("ERROR : %s\n", msg));
	exit(1);
}

char	**get_path(char **env)
{
	char	*tmp;
	char	*tmp2;

	while (ft_strncmp("PATH", *env, 4))
		env++;
	if (!*env)
		return (NULL);
	tmp = *env + 5;
	tmp2 = ft_split(tmp, ':');
	return (tmp2);
}

char	*check_path(t_pipex *pipex, char *cmd_str)
{
	char	**tmp_path;
	char	*tmp_cmd;
	char	*tmp;

	tmp_path = pipex->path;
	while (*tmp_path != NULL)
	{
		tmp = ft_strjoin(*tmp_path, "/");
		tmp_cmd = ft_strjoin(tmp, cmd_str);
		free(tmp);
		if (access(tmp_cmd, F_OK) == 0)
			if (access(tmp_cmd, X_OK) == 0)
				return (tmp_cmd);
		free(tmp_cmd);
		tmp_path++;
	}
	return (NULL);
}

t_cmd	*get_command(t_pipex *pipex, char *cmd_str)
{
	char	**splitted;
	t_cmd	*cmd;
	char	*token;
	char	*tmp;
	int		i;

	cmd = malloc(sizeof(t_cmd));
	tmp = ft_strdup(cmd_str);
	cmd->cmd = ft_strtok(cmd_str, " ");
	cmd->cmd_path = check_path(pipex, cmd->cmd);
	if (!cmd->cmd_path)
		ft_perror("no such command");
	token = ft_strtok(NULL, " ");
	if (!token)
	{
		cmd->cmd_arg = (char **)0;
		return (cmd);
	}
	splitted = (char **)malloc(sizeof(char *) * ft_get_words(tmp, ' ') - 1);
	free(tmp);
	i = 0;
	while (token)
	{
		splitted[i] = (char *)malloc(sizeof(char) * ft_strlen(token));
		splitted[i++] = token;
		token = ft_strtok(NULL, " ");
	}
	cmd->cmd_arg = splitted;
	i = 0;
	if (splitted)
		free(splitted);
	return (cmd);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	*pipex;
	t_cmd	*cmd1;
	t_cmd	*cmd2;

	pipex = malloc(sizeof(t_pipex));
	pipex->path = get_path(envp);
	if (argc < 2)
		return (ft_perror("Not enough args"));
	cmd1 = get_command(pipex, argv[2]);
	cmd2 = get_command(pipex, argv[3]);
	pipex->cmd1 = cmd1;
	pipex->cmd2 = cmd2;
	free_pipex(pipex);
	//pipex->cmd1->cmd_path = get_command(pipex, argv[2]);
	//pipex->cmd2->cmd_path = get_command(pipex, argv[3]);
	//ft_printf("%s\n", pipex->cmd1->cmd_path);
	//ft_printf("%s\n", pipex->cmd2->cmd_path);
}
/*
int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	int		end[2];
	pid_t	p1;
	pid_t	p2;
	char	*cmd[] = {"cat", NULL};

	if (argc != 5)
		return (ft_print_error("args"));

	pipe(end);

	infile = open(argv[1], O_RDONLY);
	outfile = open(argv[4], O_TRUNC | O_CREAT | O_RDWR, 0000644);

	p1 = fork();
	if (p1 == 0)
	{
		dup2(end[1], 1);
		close(end[0]);
		dup2(infile, 0);
		execve("/usr/bin/cat", cmd, envp);
	}
	char	*cmd2[] = {"grep", "flush", NULL};
	p2 = fork();
	if (p2 == 0)
	{
		dup2(end[0], 0);
		close(end[1]);
		dup2(outfile, 1);
		execve("/usr/bin/grep", cmd2, envp);
	}
	close(end);

}
*/
