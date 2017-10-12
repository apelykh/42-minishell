/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:56:14 by apelykh           #+#    #+#             */
/*   Updated: 2016/11/24 19:56:15 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int len;

	len = ft_strlen(little);
	if (!*little)
		return ((char *)big);
	while (*big)
	{
		if (ft_strncmp(big, little, len) == 0)
			return ((char *)big);
		else
			big++;
	}
	return (0);
}
