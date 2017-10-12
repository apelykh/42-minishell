/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 22:50:09 by apelykh           #+#    #+#             */
/*   Updated: 2017/10/13 22:50:09 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../includes/minishell.h"

static void		save_remn(char **rest, char *buf)
{
	char		*tmp;

	tmp = NULL;
	if (*rest)
	{
		tmp = ft_strdup(*rest);
		ft_memdel((void **)rest);
		*rest = ft_strjoin(tmp, buf);
		ft_memdel((void **)&tmp);
	}
	else
		*rest = ft_strdup(buf);
}

static int		ft_get_line(char **rest, char **line)
{
	char		*tmp;

	tmp = ft_strchr(*rest, '\n');
	if (tmp)
	{
		*line = ft_strsub(*rest, 0, tmp - *rest);
		ft_memmove(*rest, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

int				get_line(int const fd, char **line)
{
	static char	*rest = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (!line)
		return (-1);
	if (rest && ft_get_line(&rest, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		buf[ret] = '\0';
		save_remn(&rest, buf);
		ft_memset(buf, '\0', BUFF_SIZE + 1);
		if (ft_get_line(&rest, line))
			return (1);
	}
	if (rest == NULL || rest[0] == '\0')
		return (0);
	*line = rest;
	rest = NULL;
	return (1);
}
