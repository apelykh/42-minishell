/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/29 18:26:01 by apelykh           #+#    #+#             */
/*   Updated: 2017/06/29 18:26:02 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** error codes
*/
# define CMD_NOT_FOUND	1
# define NO_EXEC_PERM	2
# define EXEC_NOT_FOUND	3
# define NO_WD_CHANGE	4
# define INVAL_ARGS_NUM	5

# define MAX_PATH		1024
# define IMPL_FLAGS		"eEn"

typedef struct	s_flags
{
	int			escape_on;
	int			escape_off;
	int			no_feed;
}				t_flags;

/*
** src/env_utils.c
*/
void			handle_setenv(char **args, char ***env);
char			*ft_getenv(char *var, char **env);
char			**ft_setenv(char ***env, char *var, char *value,
							int overwrite);
char			**ft_unsetenv(char **args, char ***env);

/*
** src/exec_utils.c
*/
int				exec_cmd(char **args, char **env);

/*
** src/dir_utils.c
*/
void			handle_cd(char **args, char ***env);

/*
** src/echo_utils.c
*/
void			handle_echo(char **args, t_flags *flags);

/*
** src/process_args.c
*/
char			**process_args(char *line, char **env);

/*
** src/parse_input.c
*/
void			parse_input(t_flags *flags, char ***env);

/*
** src/signals.c
*/
void			signal_handler_input(int signal);
void			signal_handler(int signal);

/*
** src/get_line.c
*/
int				get_line(int const fd, char **line);

/*
** src/main.c
*/
void			handle_error(char *cmd, int err_code);
void			handle_exit(char ***args, char ***env, char ***to_free);

#endif
