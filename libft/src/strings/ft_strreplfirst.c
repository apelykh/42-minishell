/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplfirst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 22:53:41 by apelykh           #+#    #+#             */
/*   Updated: 2017/10/05 22:53:41 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strreplfirst(char *src, char *from, char *to)
{
	char	*repl_occ;
	char	*res;
	size_t	len_head;
	size_t	len_tail;

	res = NULL;
	if (!src || !from)
		return (src);
	if ((repl_occ = strstr(src, from)))
	{
		len_head = repl_occ - src;
		len_tail = ft_strlen(repl_occ + ft_strlen(from));
		if ((res = ft_strnew(len_head + ft_strlen(to) + len_tail)))
		{
			res = ft_strncpy(res, src, len_head);
			res = ft_strcat(res, to);
			res = ft_strcat(res, repl_occ + ft_strlen(from));
			return (res);
		}
	}
	return (src);
}
