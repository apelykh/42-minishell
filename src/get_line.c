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

static void		save_remn(char **remn, char *buf)
{
	char		*tmp;

	tmp = NULL;
	if (*remn)
	{
		tmp = ft_strdup(*remn);
		ft_memdel((void **)remn);
		*remn = ft_strjoin(tmp, buf);
		ft_memdel((void **)&tmp);
	}
	else
		*remn = ft_strdup(buf);
}

static int		ft_get_line(char **remn, char **line)
{
	char		*tmp;

	tmp = ft_strchr(*remn, '\n');
	if (tmp)
	{
		*line = ft_strsub(*remn, 0, tmp - *remn);
		ft_memmove(*remn, tmp + 1, ft_strlen(tmp));
		tmp = NULL;
		return (1);
	}
	return (0);
}

int				get_line(int const fd, char **line)
{
	static char	*remn = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	if (!line)
		return (-1);
	if (remn && ft_get_line(&remn, line))
		return (1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (ret);
		buf[ret] = '\0';
		save_remn(&remn, buf);
		ft_memset(buf, '\0', BUFF_SIZE + 1);
		if (ft_get_line(&remn, line))
			return (1);
	}
	if (remn == NULL || remn[0] == '\0')
		return (0);
	*line = remn;
	remn = NULL;
	return (1);
}
