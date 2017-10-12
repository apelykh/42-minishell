/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 20:38:05 by apelykh           #+#    #+#             */
/*   Updated: 2016/11/24 20:38:05 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*tmp;
	int			delta_len;

	tmp = big;
	delta_len = len - ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big && (big - tmp <= delta_len) && delta_len >= 0)
	{
		if (ft_strncmp(big, little, len - delta_len) == 0)
			return ((char *)big);
		else
			big++;
	}
	return (0);
}
