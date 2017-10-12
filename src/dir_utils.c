/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 12:50:16 by apelykh           #+#    #+#             */
/*   Updated: 2017/09/09 12:50:17 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <unistd.h>

static char	*append_homepath(char *path, char **env)
{
	char	*homedir;
	char	*upd_path;

	homedir = ft_getenv("HOME", env);
	upd_path = ft_strnew(ft_strlen(homedir) + ft_strlen(path) - 1);
	ft_strcat(upd_path, homedir);
	ft_strcat(upd_path, &path[1]);
	ft_strdel(&homedir);
	return (upd_path);
}

static int	change_wd(char *path, char ***env)
{
	char	*cur_wd;
	char	*old_wd;
	int		status;
	int		to_free_path;

	to_free_path = (path[0] == '~');
	if (path[0] == '~')
		path = append_homepath(path, *env);
	old_wd = ft_strnew(MAX_PATH);
	getcwd(old_wd, MAX_PATH);
	if ((status = chdir(path)) == 0)
	{
		cur_wd = ft_strnew(MAX_PATH);
		getcwd(cur_wd, MAX_PATH);
		ft_setenv(env, "OLDPWD", old_wd, 1);
		ft_setenv(env, "PWD", cur_wd, 1);
		ft_strdel(&old_wd);
		ft_strdel(&cur_wd);
		if (to_free_path)
			ft_strdel(&path);
		return (0);
	}
	ft_strdel(&old_wd);
	handle_error(path, NO_WD_CHANGE);
	return (-1);
}

void	handle_cd(char **args, char ***env)
{
	char *tgt_dir;

	tgt_dir = NULL;
	if (ft_arrlen(args) > 2)
	{
		handle_error("cd", INVAL_ARGS_NUM);
		ft_putendl("usage: cd dir");
		return ;
	}
	if (ft_arrlen(args) == 1 || (args[1] && !ft_strcmp(args[1], "~")))
		tgt_dir = ft_getenv("HOME", *env);
	else if (args[1] && !ft_strcmp(args[1], "-"))
		tgt_dir = ft_getenv("OLDPWD", *env);
	if (tgt_dir)
	{
		change_wd(tgt_dir, env);
		ft_strdel(&tgt_dir);
	}
	else
		change_wd(args[1], env);
}
