/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memfalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:09:56 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/05 18:09:57 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcalloc(size_t size, int c, int term)
{
	char *tmp;
	char *res;

	if (term)
		size += 1;
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	tmp = res;
	while (size-- > 0)
		*tmp++ = (unsigned char)c;
	if (term)
		*--tmp = '\0';
	return (res);
}
