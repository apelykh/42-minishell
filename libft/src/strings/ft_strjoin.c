/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:00:49 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/08 17:00:49 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	res = ft_strnew(sizeof(*s1) * (len + ft_strlen(s2)));
	if (!res)
		return (NULL);
	ft_strcat(res, s1);
	ft_strcat(res + len, s2);
	return (res);
}
