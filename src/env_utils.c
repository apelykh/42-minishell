/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 12:50:29 by apelykh           #+#    #+#             */
/*   Updated: 2017/09/09 12:50:32 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

char	*ft_getenv(char *var, char **env)
{
	char	*hook;
	char	*buf;
	size_t	var_len;
	int		i;

	i = 0;
	while (env[i])
	{
		var_len = ft_strlen(var);
		if (!ft_strncmp(env[i], var, var_len) && env[i][var_len] == '=')
		{
			hook = ft_strchr(env[i], '=') + 1;
			buf = ft_strdup(hook);
			return (buf);
		}
		i++;
	}
	return (NULL);
}

void	handle_setenv(char **args, char ***env)
{
	int		args_len;

	args_len = ft_arrlen(args);
	if (args_len < 2 || args_len > 3)
	{
		handle_error("setenv", INVAL_ARGS_NUM);
		ft_putendl("usage: setenv var_name [var_value]");
		return ;
	}
	if (args_len == 3)
		ft_setenv(env, args[1], args[2], 1);
	else
		ft_setenv(env, args[1], "", 1);
}

char	**ft_setenv(char ***env, char *var, char *value, int overwrite)
{
	char	**new_env;
	int		var_i;
	int		i;

	i = -1;
	var_i = -1;
	while ((*env)[++i])
		if (ft_strstr((*env)[i], var) == (*env)[i])
			var_i = i;
	if (var_i != -1 && overwrite)
	{
		free((*env)[var_i]);
		(*env)[var_i] = ft_strjoindelim(var, "=", value);
	}
	else if (var_i == -1)
	{
		new_env = ft_arrcpyextra(*env, 1);
		new_env[ft_arrlen(*env)] = ft_strjoindelim(var, "=", value);
		ft_arrfree(env);
		*env = new_env;
	}
	return (*env);
}

char	**ft_unsetenv(char **args, char ***env)
{
	char	**new_env;
	char	*var_val;

	if (ft_arrlen(args) != 2)
	{
		handle_error("unsetenv", INVAL_ARGS_NUM);
		ft_putendl("usage: setenv var_name [var_value]");
		return (NULL);
	}
	if (!(var_val = ft_getenv(args[1], *env)))
		return (*env);
	ft_strdel(&var_val);
	new_env = ft_arrcpyexcept(*env, args[1]);
	ft_arrfree(env);
	*env = new_env;
	return (*env);
}
