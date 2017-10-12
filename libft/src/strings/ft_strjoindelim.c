/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoindelim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:19:23 by apelykh           #+#    #+#             */
/*   Updated: 2017/09/16 16:19:24 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoindelim(char const *s1, char const *delim, char const *s2)
{
	char	*res;
	int		len;

	if (!s1 || !delim || !s2)
		return (NULL);
	len = ft_strlen(s1);
	res = ft_strnew(sizeof(*s1) * (len + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	ft_strcat(res, s1);
	ft_strcat(res, delim);
	ft_strcat(res, s2);
	return (res);
}
