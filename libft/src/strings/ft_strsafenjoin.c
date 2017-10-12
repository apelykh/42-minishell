/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsafenjoin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:23:43 by apelykh           #+#    #+#             */
/*   Updated: 2017/01/19 15:23:43 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_strsafenjoin.c
**
**	len2: 	number of s2 symbols to be joined.
**			If len2 == -1, the whole string is joined
**
**	to_free: if to_free == 1, s1 is freed
**			 if to_free == 2, both s1 and s2 are freed
*/

char	*ft_strsafenjoin(char **s1, char **s2, int len2, int to_free)
{
	char	*res;
	int		l1;
	int		l2;

	if (!*s2)
		return (NULL);
	l1 = *s1 ? (int)ft_strlen(*s1) : 0;
	l2 = (len2 != -1) ? len2 : (int)ft_strlen(*s2);
	res = ft_strnew(sizeof(char) * (l1 + l2));
	if (!res)
		return (NULL);
	if (*s1)
		ft_strcat(res, *s1);
	ft_strncat(res + l1, *s2, l2);
	if (to_free == 1 || to_free == 2)
		ft_strdel(s1);
	if (to_free == 2)
		ft_strdel(s2);
	return (res);
}
