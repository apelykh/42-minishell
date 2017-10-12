/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 15:34:18 by apelykh           #+#    #+#             */
/*   Updated: 2016/11/24 15:34:18 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	char *res;

	res = dest;
	while (len > 0 && *src)
	{
		*res++ = *src++;
		len--;
	}
	while (len-- > 0)
		*res++ = '\0';
	return (dest);
}
