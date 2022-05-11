/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_cmd.1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brda-sil <brda-sil@students.42angouleme    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 00:30:25 by brda-sil          #+#    #+#             */
/*   Updated: 2022/05/11 15:58:41 by brda-sil         ###   ########.fr       */
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

t_cmd	*get_command(t_pipex *pipex, char *cmd_str)
{
	t_cmd	*cmd;
	char	*token;

	cmd = malloc(sizeof(t_cmd));
	cmd->cmd_str = (char *)malloc(sizeof(char) * ft_strlen(cmd_str) + 1);
	ft_strcpy(cmd->cmd_str, cmd_str);
	token = ft_strtok(cmd_str, " ");
	cmd->cmd_path = check_path(pipex, token);
	if (!cmd->cmd_path)
	{
		free_unfinished(pipex, cmd);
		ft_error(cmd_str);
	}
	return (cmd);
}
