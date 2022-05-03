/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 00:30:25 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/03 18:50:33 by brda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **env)
{
	char	*tmp;

	while (ft_strncmp("PATH", *env, 4))
		env++;
	if (!*env)
		return (NULL);
	tmp = *env + 5;
	return (ft_split(tmp, ':'));
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
		if (access(tmp_cmd, F_OK | X_OK) == 0)
			return (tmp_cmd);
		free(tmp_cmd);
		tmp_path++;
	}
	return (NULL);
}

void	get_command_arg(t_cmd *cmd, char *token)
{
	size_t	i;

	i = 1;
	while (token)
	{
		cmd->cmd[i] = (char *)malloc(sizeof(char) * ft_strlen(token) + 1);
		ft_strcpy(cmd->cmd[i], token);
		token = ft_strtok(NULL, " ");
		i++;
	}
}

t_cmd	*get_command(t_pipex *pipex, char *cmd_str)
{
	t_cmd	*cmd;
	char	*token;
	int		i;

	i = 0;
	cmd = malloc(sizeof(t_cmd));
	cmd->size = ft_get_words(cmd_str, ' ');
	cmd->cmd = (char **)malloc(sizeof(char *) * cmd->size + 1);
	token = ft_strtok(cmd_str, " ");
	cmd->cmd[i] = (char *)malloc(sizeof(char) * ft_strlen(token) + 1);
	ft_strcpy(cmd->cmd[i], token);
	cmd->cmd_path = check_path(pipex, cmd->cmd[i]);
	if (!cmd->cmd_path)
	{
		free_unfinished(pipex, cmd);
		ft_error(cmd_str);
	}
	if (cmd->size == 1)
		return (cmd);
	token = ft_strtok(NULL, " ");
	get_command_arg(cmd, token);
	return (cmd);
}
