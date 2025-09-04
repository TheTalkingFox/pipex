/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apchelni <apchelni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 00:56:05 by apchelni          #+#    #+#             */
/*   Updated: 2025/03/01 01:16:49 by apchelni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_cmd
{
	char			*cmd;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_data
{
	char			**env_path;
	pid_t			pid1;
	pid_t			pid2;
	int				fd[2];
	int				fd1;
	int				fd2;
	t_cmd			*cmds;
	int				mod;
}					t_data;

int					check_permission(t_data *data, char *fd_name,
						int file_order);
int					parse_cmd(t_data *data, int argc, char **argv);
int					get_env_path(t_data *data, char **envp);
int					check_input(t_data *data, int argc, char **argv,
						char **envp);

void				free_cmds(t_cmd *cmd);
void				free_env_path(char **env_path);
void				free_all(t_data *data);
void				handle_error(char *str, int error_code);

void				add_sec_proc(t_data *data, char **argv, char **envp);
void				exec_child(t_data *data, int *fd, char **argv, char **envp);
int					execute_cmd(t_data *data, char *cmd, char **envp);
char				*check_path(t_data *data, char *cmd);

#endif
