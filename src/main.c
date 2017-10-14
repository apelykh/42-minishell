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
#include <signal.h>

char	*g_line;
pid_t	g_child_pid;

void	handle_exit(char ***args, char ***env, char ***to_free)
{
	ft_strdel(&g_line);
	ft_arrfree(args);
	ft_arrfree(env);
	ft_arrfree(to_free);
	exit(0);
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
		get_line(0, &g_line);
		signal(SIGINT, signal_handler);
		signal(SIGQUIT, signal_handler);
		if (g_line == NULL)
		{
			ft_putendl("^D");
			continue;
		}
		if (g_line && ft_strlen(g_line) > 0)
			parse_input(&flags, &env);
		ft_strdel(&g_line);
	}
	ft_arrfree(&env);
	return (0);
}
