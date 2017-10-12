/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 17:26:54 by apelykh           #+#    #+#             */
/*   Updated: 2017/09/17 17:26:54 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <sys/wait.h>
#include <sys/stat.h>

extern pid_t	g_child_pid;

int		check_exec(char *exec_path)
{
	struct stat	exec_stat;

	if (!access(exec_path, X_OK) && !lstat(exec_path, &exec_stat))
	{
		if ((exec_stat.st_mode & S_IXUSR) &&
			(exec_stat.st_mode & S_IXGRP) &&
			(exec_stat.st_mode & S_IXOTH))
			return (1);
		else
		{
			handle_error(exec_path, NO_EXEC_PERM);
			return (0);
		}
	}
	return (0);
}

int		run_child_process(char *exec_path, char **args, char **env)
{
	int		status;

	status = check_exec(exec_path);
	if (status)
	{
		g_child_pid = fork();
		if (g_child_pid == 0)
			execve(exec_path, args, env);
		wait(0);
		g_child_pid = 0;
	}
	return (status);
}

int		exec_cmd(char **args, char **env)
{
	char	**paths;
	char	*paths_val;
	char	*full_path;
	int		status;
	int		i;

	i = 0;
	status = 0;
	if ((status = run_child_process(args[0], args, env)))
		return (status);
	if (!(paths_val = ft_getenv("PATH", env)))
		return (0);
	paths = ft_strsplit(paths_val, ':');
	while (paths[i])
	{
		full_path = ft_strjoindelim(paths[i], "/", args[0]);
		status = run_child_process(full_path, args, env);
		ft_strdel(&full_path);
		if (status)
			break ;
		i++;
	}
	ft_strdel(&paths_val);
	ft_arrfree(&paths);
	return (status);
}
