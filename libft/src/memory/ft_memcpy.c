/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:59:15 by apelykh           #+#    #+#             */
/*   Updated: 2016/11/28 18:59:15 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dst_cast;
	unsigned char *src_cast;

	dst_cast = (unsigned char*)dst;
	src_cast = (unsigned char*)src;
	while (n > 0)
	{
		*dst_cast++ = *src_cast++;
		n--;
	}
	return (dst);
}
