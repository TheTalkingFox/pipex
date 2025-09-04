/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:54:42 by apchelni          #+#    #+#             */
/*   Updated: 2025/03/01 00:26:33 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_cmds(t_cmd *cmd)
{
	t_cmd	*tmp;

	while (cmd)
	{
		tmp = cmd;
		cmd = cmd->next;
		free(tmp->cmd);
		free(tmp);
	}
}

void	free_env_path(char **env_path)
{
	int	i;

	i = -1;
	while (env_path[++i] != NULL)
		free(env_path[i]);
	free(env_path);
}

void	free_all(t_data *data)
{
	int	i;

	i = -1;
	if (data->env_path != NULL)
		free_env_path(data->env_path);
	free_cmds(data->cmds);
	if (data->fd1 >= 0)
		close(data->fd1);
	if (data->fd2 >= 0)
		close(data->fd2);
}

void	handle_error(char *str, int error_code)
{
	if (error_code == 0)
	{
		write(2, str, ft_strlen(str));
		write(2, ": no such file or directory\n", 28);
	}
	else if (error_code == 1)
	{
		write(2, str, ft_strlen(str));
		write(2, ": permission denied\n", 20);
	}
	else if (error_code == 2)
	{
		write(2, str, ft_strlen(str));
		write(2, ": command not found\n", 20);
	}
}
