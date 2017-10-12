/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpyextra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:04:43 by apelykh           #+#    #+#             */
/*   Updated: 2017/09/16 16:04:43 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrcpyextra(char **arr, size_t extra)
{
	size_t	arrlen;
	char	**res;
	int		i;

	arrlen = ft_arrlen(arr);
	res = ft_arrnew(arrlen + extra);
	i = 0;
	while (arr[i])
	{
		res[i] = ft_strdup(arr[i]);
		i++;
	}
	return (res);
}
