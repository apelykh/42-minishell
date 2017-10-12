/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:49:48 by apelykh           #+#    #+#             */
/*   Updated: 2016/11/30 15:49:48 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void *res;

	res = (void *)s;
	while (n > 0)
	{
		if (*(unsigned char *)res == (unsigned char)c)
			return (res);
		res++;
		n--;
	}
	return (0);
}
