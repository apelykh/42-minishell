/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 17:09:28 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/07 17:09:29 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;
	char			*tmp;

	i = 0;
	if (!s)
		return (NULL);
	tmp = ft_strnew(sizeof(*s) * ft_strlen(s));
	if (!tmp)
		return (NULL);
	res = tmp;
	while (s[i])
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	return (res);
}
