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
//!!!!!!!!!!!
// #include <stdio.h>

int		choose_sym(char c)
{
	if (c == 'a')
		return (7);
	if (c == 'b')
		return (8);
	if (c == 'n')
		return (10);
	if (c == '\\')
		return (92);
	if (c == 'f')
		return (12);
	if (c == 'r')
		return (13);
	if (c == 't')
		return (9);
	if (c == 'v')
		return (11);
	return (0);
}

void	ft_echostr(char *str, t_flags *flags)
{
	int i;
	int c;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\' && str[i + 1] && flags->e)
		{
			c = choose_sym(str[i + 1]);
			ft_putchar(c);
			i += 2;
		}
		else
			ft_putchar(str[i++]);
	}
}

int		process_flag(char *arg, t_flags *flags)
{
	int i;

	i = 0;
	while (arg[++i])
		if (!ft_strrchr(IMPL_FLAGS, arg[i]))
			return (0);
	i = 0;
	while (arg[++i])
	{
		arg[i] == 'e' ? flags->e = 1 : 0;
		arg[i] == 'E' ? flags->E = 1 : 0;
		arg[i] == 'n' ? flags->n = 1 : 0;
	}
	return (1);
}

int		process_flags(char **args, t_flags *flags)
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

void	handle_echo(char **args, t_flags *flags)
{
	int		first_arg;

	first_arg = process_flags(args, flags);
	// printf("=============================\n");
	// printf("flags:\n");
	// printf("e: %d\n", flags->e);
	// printf("E: %d\n", flags->E);
	// printf("n: %d\n", flags->n);
	// printf("=============================\n");
	// printf("args start with: %d\n", first_arg);
	// printf("=============================\n");
	while (first_arg > 0 && args[first_arg])
	{
		ft_echostr(args[first_arg], flags);
		if (args[first_arg + 1])
			ft_putchar(' ');
		first_arg++;
	}
	if (!flags->n)
		ft_putchar('\n');
}
