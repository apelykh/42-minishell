/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 22:59:59 by apelykh           #+#    #+#             */
/*   Updated: 2017/10/12 23:00:00 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

extern char	*g_line;

static void	refresh_flags(t_flags *flags)
{
	flags->e = 0;
	flags->E = 0;
	flags->n = 0;
}

void		parse_line(char *line, t_flags *flags, char ***env)
{
	char **args;

	args = process_args(line, *env);
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
			handle_exit(&args, env);
		else if (!ft_strcmp(line, "echo") || ft_strstr(line, "echo ") == line)
			handle_echo(args, flags);
		else if (exec_cmd(args, *env) == 0)
			handle_error(line, CMD_NOT_FOUND);
	}
	ft_arrfree(&args);
}

void		parse_input(t_flags *flags, char ***env)
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
