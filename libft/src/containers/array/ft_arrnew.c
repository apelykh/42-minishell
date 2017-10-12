/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 16:01:11 by apelykh           #+#    #+#             */
/*   Updated: 2017/09/16 16:01:11 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_arrnew(size_t len)
{
	char **res;

	res = (char**)malloc(sizeof(char*) * (len + 1));
	if (!res)
		return (NULL);
	while (len)
		res[len--] = NULL;
	res[len] = NULL;
	return (res);
}
