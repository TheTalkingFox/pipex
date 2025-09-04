/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:54:42 by apchelni          #+#    #+#             */
/*   Updated: 2025/03/01 01:05:31 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_path(t_data *data, char *cmd)
{
	char	*path;
	char	*tmp;
	int		i;

	i = -1;
	tmp = NULL;
	while (data->env_path[++i] != NULL)
	{
		if (tmp != NULL)
			free(tmp);
		path = ft_strjoin(data->env_path[i], "/");
		if (!path)
			return (free(tmp), write(2, "Path alloc failed\n", 18), NULL);
		tmp = ft_strjoin(path, cmd);
		free(path);
		if (!tmp)
			return (write(2, "Path alloc failed\n", 18), NULL);
		if (access(tmp, X_OK) == 0)
			return (tmp);
	}
	return (free(tmp), NULL);
}

int	execute_cmd(t_data *data, char *cmd, char **envp)
{
	char	**cmd_name;
	char	*path;

	path = NULL;
	cmd_name = ft_split(cmd, ' ');
	if (!cmd_name)
		return (handle_error(cmd, 2), 0);
	if (cmd_name[0][0] == '/' || (cmd_name[0][0] == '.'
			&& cmd_name[0][1] == '/'))
	{
		if (access(*cmd_name, X_OK) == 0)
			path = *cmd_name;
		else
			return (free_env_path(cmd_name), handle_error(cmd, 0), 0);
	}
	else
		path = check_path(data, cmd_name[0]);
	if (!path)
		return (free_env_path(cmd_name), handle_error(cmd, 2), 0);
	if (execve(path, cmd_name, envp) == -1)
		return (free(path), free_env_path(cmd_name), free_all(data),
			perror("Execve: "), 0);
	return (free(path), free_env_path(cmd_name), 1);
}

void	exec_child(t_data *data, int *fd, char **argv, char **envp)
{
	if (data->mod == 2)
	{
		dup2(data->fd1, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
	}
	else if (data->mod == 3)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(data->fd2, STDOUT_FILENO);
	}
	close(fd[0]);
	close(fd[1]);
	close(data->fd1);
	close(data->fd2);
	if (!execute_cmd(data, argv[data->mod], envp))
	{
		free_all(data);
		if (data->mod == 3)
			exit(127);
		exit(0);
	}
}

void	add_sec_proc(t_data *data, char **argv, char **envp)
{
	int	status;

	data->pid2 = fork();
	if (data->pid2 == -1)
	{
		free_all(data);
		perror("Fork 2: ");
		exit(1);
	}
	else if (data->pid2 == 0)
	{
		data->mod = 3;
		exec_child(data, data->fd, argv, envp);
	}
	else
	{
		close(data->fd[0]);
		close(data->fd[1]);
		waitpid(data->pid1, NULL, 0);
		waitpid(data->pid2, &status, 0);
		free_all(data);
		exit(status >> 8);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc != 5 || *argv[2] == '\0' || *argv[3] == '\0')
		return (write(2, "Incorrect input\n", 16), 1);
	data.fd1 = -1;
	data.fd2 = -1;
	data.cmds = NULL;
	if (!check_input(&data, argc, argv, envp))
		return (1);
	if (pipe(data.fd) == -1)
		return (perror("Pipe: "), 1);
	data.pid1 = fork();
	if (data.pid1 == -1)
		return (free_all(&data), perror("Fork 1: "), 1);
	else if (data.pid1 == 0)
	{
		data.mod = 2;
		exec_child(&data, data.fd, argv, envp);
	}
	else
		add_sec_proc(&data, argv, envp);
}
