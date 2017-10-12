/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 19:24:10 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/21 19:24:10 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_box	*manage_fd(int fd, t_box *head, t_box **cur)
{
	t_box *tmp;

	tmp = head;
	while (tmp)
	{
		if (tmp->fd == fd)
		{
			*cur = tmp;
			return (head);
		}
		tmp = tmp->next;
	}
	*cur = NULL;
	if (!(tmp = (t_box *)malloc(sizeof(t_box))))
		return (NULL);
	tmp->fd = fd;
	tmp->str = NULL;
	tmp->next = (head ? head : NULL);
	return (tmp);
}

static int		parse_str(char **str, char **line)
{
	int		i;
	char	*remn;

	i = 0;
	if (!str || !*str)
		return (0);
	while ((*str)[i])
	{
		if ((*str)[i] == '\n')
		{
			*line = ft_strsub(*str, 0, i);
			remn = ft_strsub(*str, i + 1, ft_strlen(*str) - i - 1);
			free(*str);
			*str = remn;
			return (1);
		}
		i++;
	}
	return (0);
}

static int		parse_buf(char *buf, char **str, int ch_read, char **line)
{
	int		i;
	int		remn_size;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			*line = ft_strsafenjoin(str, &buf, i, 1);
			remn_size = (ch_read < BUFF_SIZE ? ch_read : BUFF_SIZE) - i - 1;
			*str = ft_strsub(buf, i + 1, remn_size);
			ft_strdel(&buf);
			return (1);
		}
		i++;
	}
	if (ch_read < BUFF_SIZE)
	{
		*line = ft_strsafenjoin(str, &buf, ch_read, 1);
		ft_strdel(&buf);
		return (1);
	}
	*str = ft_strsafenjoin(str, &buf, -1, 1);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_box	*head;
	t_box			*node;
	char			*buf;
	int				ch_read;

	if (fd < 0 || !line)
		return (-1);
	head = manage_fd(fd, head, &node);
	if (!node)
		node = head;
	if (parse_str(&(node->str), line))
		return (1);
	buf = ft_strnew(BUFF_SIZE);
	while ((ch_read = read(fd, buf, BUFF_SIZE)) > 0)
		if (parse_buf(buf, &(node->str), ch_read, line))
			return (1);
	if (ch_read == 0 && node->str && *(node->str) != '\0')
	{
		*line = ft_strdup(node->str);
		ft_strdel(&node->str);
		return (1);
	}
	return (ch_read);
}
