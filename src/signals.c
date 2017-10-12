/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/10 21:38:53 by apelykh           #+#    #+#             */
/*   Updated: 2017/10/10 21:38:54 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"
#include <signal.h>

extern char		*g_line;
extern pid_t	g_child_pid;

void	signal_handler(int signal)
{
	if (g_child_pid > 0)
		kill(g_child_pid, signal);
}

void	signal_handler_input(int signal)
{
	if (signal == SIGINT || signal == SIGQUIT)
	{
		ft_putchar('\n');
		ft_putstr("minishell$> ");
	}
}
