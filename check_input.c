/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:54:42 by apchelni          #+#    #+#             */
/*   Updated: 2025/03/01 00:02:03 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_permission(t_data *data, char *fd_name, int file_order)
{
	if (file_order == 1)
	{
		if (access(fd_name, F_OK) != -1)
		{
			if (access(fd_name, R_OK) == -1)
				return (handle_error(fd_name, 1), 0);
		}
		else
		{
			handle_error(fd_name, 0);
			free_all(data);
			exit(0);
		}
	}
	else
		if (access(fd_name, F_OK) != -1)
			if (access(fd_name, R_OK) == -1 || access(fd_name, W_OK) == -1)
				return (handle_error(fd_name, 1), 0);
	return (1);
}

int	parse_cmd(t_data *data, int argc, char **argv)
{
	t_cmd	*new_cmd;
	t_cmd	*last;
	int		i;

	last = NULL;
	i = 1;
	while (++i < argc - 1)
	{
		new_cmd = (t_cmd *)malloc(sizeof(t_cmd));
		if (!new_cmd)
			return (free_cmds(data->cmds), 0);
		new_cmd->cmd = ft_strdup(argv[i]);
		if (!new_cmd->cmd)
			return (free(new_cmd->cmd), free(new_cmd), free_cmds(data->cmds),
				0);
		new_cmd->next = NULL;
		if (!last)
			data->cmds = new_cmd;
		else
			last->next = new_cmd;
		last = new_cmd;
	}
	return (1);
}

int	get_env_path(t_data *data, char **envp)
{
	int	cmp;
	int	i;

	i = -1;
	while (envp[++i])
	{
		cmp = ft_strncmp(envp[i], "PATH=", 5);
		if (cmp == 0)
		{
			data->env_path = ft_split(envp[i] + 5, ':');
			break ;
		}
	}
	if (!data->env_path)
		return (write(2, "PATH not found\n", 15), 0);
	return (1);
}

int	check_input(t_data *data, int argc, char **argv, char **envp)
{
	if (!get_env_path(data, envp))
		return (0);
	if (!check_permission(data, argv[1], 1))
		return (free_all(data), 0);
	data->fd1 = open(argv[1], O_RDONLY);
	if (data->fd1 == -1)
		return (handle_error(argv[1], 0), free_all(data), 0);
	if (!check_permission(data, argv[argc - 1], 2))
		return (free_all(data), 0);
	data->fd2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (data->fd2 == -1)
		return (handle_error(argv[argc - 1], 0), free_all(data), 0);
	if (!parse_cmd(data, argc, argv))
		return (free_all(data), write(2, "Error parsing commands\n", 23), 0);
	return (1);
}
