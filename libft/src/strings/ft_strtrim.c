/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:36:58 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/08 17:36:58 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	int		len;

	if (!s)
		return (NULL);
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	len = ft_strlen(s);
	while (*s && (*(s + len - 1) == ' ' || *(s + len - 1) == '\n' || \
			*(s + len - 1) == '\t'))
		len--;
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	ft_strncpy(res, s, len);
	return (res);
}
