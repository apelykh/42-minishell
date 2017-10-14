/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 22:20:56 by apelykh           #+#    #+#             */
/*   Updated: 2017/10/08 22:20:56 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

static int	choose_sym(char c)
{
	if (c == 'a')
		return ('\a');
	if (c == 'b')
		return ('\b');
	if (c == 'n')
		return ('\n');
	if (c == '\\')
		return ('\\');
	if (c == 'f')
		return ('\f');
	if (c == 'r')
		return ('\r');
	if (c == 't')
		return ('\t');
	if (c == 'v')
		return ('\v');
	return (0);
}

static void	ft_echostr(char *str, t_flags *flags)
{
	int		i;
	int		sym;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] && flags->escape_on)
		{
			sym = choose_sym(str[i + 1]);
			i++;
		}
		else
			sym = str[i];
		ft_putchar(sym);
		i++;
	}
}

static int	process_flag(char *arg, t_flags *flags)
{
	int		i;

	i = 0;
	while (arg[++i])
		if (!ft_strrchr(IMPL_FLAGS, arg[i]))
			return (0);
	i = 0;
	while (arg[++i])
	{
		flags->escape_on = (arg[i] == 'e');
		flags->escape_off = (arg[i] == 'E');
		flags->no_feed = (arg[i] == 'n');
	}
	return (1);
}

static int	process_flags(char **args, t_flags *flags)
{
	int		first_arg;
	int		flag;
	int		i;

	i = 1;
	flag = 1;
	first_arg = -1;
	while (args[i])
	{
		if (flag && args[i][0] == '-' && args[i][1])
			flag = process_flag(args[i], flags);
		else
		{
			flag = 0;
			if (first_arg == -1 && i > 0 && (args[i][0] != '-' || !args[i][1]))
				first_arg = i;
		}
		i++;
	}
	return (first_arg);
}

void		handle_echo(char **args, t_flags *flags)
{
	int		first_arg;

	first_arg = process_flags(args, flags);
	while (first_arg > 0 && args[first_arg])
	{
		ft_echostr(args[first_arg], flags);
		if (args[first_arg + 1])
			ft_putchar(' ');
		first_arg++;
	}
	if (!flags->no_feed)
		ft_putchar('\n');
}
