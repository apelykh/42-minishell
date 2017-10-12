/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:03:24 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/07 16:03:25 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*tmp;

	if (!s)
		return (NULL);
	tmp = ft_strnew(sizeof(*s) * ft_strlen(s));
	if (!tmp)
		return (NULL);
	res = tmp;
	while (*s)
		*tmp++ = f(*s++);
	return (res);
}
