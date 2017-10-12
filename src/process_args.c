/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:50:09 by apelykh           #+#    #+#             */
/*   Updated: 2017/10/05 22:50:09 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

static int	join_var(char **res, char *ch_pos, char **env)
{
	char	*var_name;
	char	*val;
	char	*tmp;
	int		i;

	i = 1;
	while (ch_pos && ch_pos[i] && ch_pos[i] != ' ' && ch_pos[i] != '$')
		i++;
	if (i > 1)
	{
		var_name = ft_strndup(ch_pos, &(ch_pos[i]) - ch_pos);
		val = ft_getenv(var_name + 1, env);
		if (val)
		{
			tmp = *res ? ft_strjoin(*res, val) : ft_strdup(val);
			if (*res)
				ft_strdel(res);
			*res = tmp;
			ft_strdel(&val);
		}
		ft_strdel(&var_name);
	}
	return (i);
}

static char	*process_arg(char *str, char **env)
{
	char	*ch_pos;
	char	*ptr;
	char	*res;
	char	*tmp;

	res = NULL;
	ptr = str;
	while ((ptr - str) < (int)ft_strlen(str))
	{
		ch_pos = ft_strchr(ptr, '$');
		if (!ch_pos || (ch_pos && (ch_pos > ptr)))
		{
			if (!ch_pos)
				tmp = (res) ? ft_strjoin(res, ptr) : ft_strdup(ptr);
			else if (ch_pos && (ch_pos > ptr))
				tmp = (res) ? ft_strnjoin(res, ptr, ch_pos - ptr) :
							ft_strndup(ptr, ch_pos - ptr);
			ft_strdel(&res);
			res = tmp;
			if (!ch_pos)
				return (res);
		}
		ptr = (ch_pos + join_var(&res, ch_pos, env));
	}
	return (res);
}

char	**process_args(char *line, char **env)
{
	char	**args;
	char	*res;
	char	*tmp;
	int		i;

	args = ft_strsplitspaceswithquotes(line);
	i = 0;
	while (args[i] && ft_strlen(args[i]) > 0)
	{
		res = process_arg(args[i], env);
		if (res)
		{
			tmp = args[i];
			args[i] = res;
			ft_strdel(&tmp);
		}
		i++;
	}
	return (args);
}
