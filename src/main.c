/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 16:29:29 by apelykh           #+#    #+#             */
/*   Updated: 2017/06/29 16:29:30 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
//!!!!!!!!!!!
#include <stdio.h>
#include <signal.h>

char	*g_line;
pid_t	g_child_pid;

void	refresh_flags(t_flags *flags)
{
	flags->e = 0;
	flags->E = 0;
	flags->n = 0;
}

void	handle_error(char *cmd, int err_code)
{
	ft_putstr("minishell: ");
	if (err_code == CMD_NOT_FOUND)
		ft_putstr("command not found: ");
	else if (err_code == NO_EXEC_PERM)
		ft_putstr("permission denied: ");
	else if (err_code == NO_WD_CHANGE)
		ft_putstr("no such file or directory: ");
	else if (err_code == INVAL_ARGS_NUM)
		ft_putstr("invalid number of arguments: ");
	ft_putendl(cmd);
}

void	parse_line(char *line, t_flags *flags, char ***env)
{
	char **args;

	args = process_args(line, *env);
	printf("=============================\n");
	printf("args after process:\n");
	ft_arrprint(args);
	printf("=============================\n");
	if (ft_arrlen(args) > 0 && ft_strcmp("", args[0]))
	{
		if (!ft_strcmp(line, "env") || !ft_strcmp(line, "setenv") ||
			!ft_strcmp(line, "unsetenv"))
			ft_arrprint(*env);
		else if (!ft_strcmp(line, "cd") || ft_strstr(line, "cd ") == line)
			handle_cd(args, env);
		else if (ft_strstr(line, "setenv ") == line)
			handle_setenv(args, env);
		else if (ft_strstr(line, "unsetenv ") == line)
			ft_unsetenv(args, env);
		else if (!ft_strcmp(line, "exit"))
			exit(0);
		else if (!ft_strcmp(line, "echo") || ft_strstr(line, "echo ") == line)
			handle_echo(args, flags);
		else if (exec_cmd(args, *env) == 0)
			handle_error(line, CMD_NOT_FOUND);
	}
	ft_arrfree(&args);
}

void	parse_input(t_flags *flags, char ***env)
{
	char	**split;
	int		i;

	i = 0;
	if (g_line)
	{
		split = ft_strsplit(g_line, ';');
		while (split[i])
		{
			refresh_flags(flags);
			if (ft_strlen(split[i]) > 0)
				parse_line(split[i], flags, env);
			i++;
		}
		ft_arrfree(&split);
	}
}

int		main(int argc, char **argv, char **environ)
{
	t_flags	flags;
	char	**env;

	if (!argc || !argv || !environ)
		return (0);
	env = ft_arrcpy(environ);
	while (1)
	{
		ft_putstr("minishell$> ");
		signal(SIGINT, signal_handler_input);
		signal(SIGQUIT, signal_handler_input);
		get_next_line(0, &g_line);
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
		if (g_line && ft_strlen(g_line) > 0)
			parse_input(&flags, &env);
		ft_strdel(&g_line);
	}
	ft_arrfree(&env);
	while (1);
	return (0);
}
