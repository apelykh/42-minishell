/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:06:48 by apelykh           #+#    #+#             */
/*   Updated: 2016/11/30 14:06:49 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const void	*s;
	void		*d;

	d = dst;
	s = src;
	while (len > 0)
	{
		if ((unsigned long)dst < (unsigned long)src)
			*(unsigned char *)d++ = *(unsigned char *)s++;
		else
			*(unsigned char *)(d + len - 1) = *(unsigned char *)(s + len - 1);
		len--;
	}
	return (dst);
}
