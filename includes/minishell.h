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
	int e;
	int E;
	int n;
}				t_flags;

/*
** src/env_utils.c
*/
void	handle_setenv(char **args, char ***env);
char	*ft_getenv(char *var, char **env);
char	**ft_setenv(char ***env, char *var, char *value, int overwrite);
char	**ft_unsetenv(char **args, char ***env);

/*
** src/exec_utils.c
*/
int		check_exec(char *exec_path);
int		run_child_process(char *exec_path, char **args, char **env);
int		exec_cmd(char **args, char **env);

/*
** src/dir_utils.c
*/
int		change_wd(char *path, char ***env);
void	handle_cd(char **args, char ***env);

/*
** src/echo_utils.c
*/
void	handle_echo(char **args, t_flags *flags);

/*
** src/process_args.c
*/
int		update_arg(char *ch_pos, char *ch2_pos, char **arg, char **env);
char	**process_args(char *line, char **env);


void    signal_handler_input(int signal);
void    signal_handler(int signal);
void	handle_error(char *cmd, int err_code);

#endif
