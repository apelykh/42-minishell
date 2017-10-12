/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 20:12:45 by apelykh           #+#    #+#             */
/*   Updated: 2017/10/08 20:12:45 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char	*res;

	res = NULL;
	if (s1 && s2)
	{
		res = ft_strnew(ft_strlen(s1) + len);
		if (!res)
			return (NULL);
		ft_strcpy(res, s1);
		ft_strncat(res, s2, len);
	}
	return (res);
}
