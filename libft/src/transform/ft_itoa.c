/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 05:04:44 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/10 05:04:44 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char		*result;
	int			size;
	int			i;

	i = n;
	size = (i < 0) ? 2 : 1;
	while (n /= 10)
		size++;
	result = ft_strnew(size);
	if (!result)
		return (NULL);
	if (i < 0)
		result[0] = '-';
	while (size--)
	{
		result[size] = ft_abs(i % 10) + '0';
		i /= 10;
		if (i == 0)
			break ;
	}
	return (result);
}
