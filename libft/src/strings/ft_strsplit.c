/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:54:02 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/08 19:54:03 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	const char	*tmp;
	int			count;

	count = 0;
	tmp = s;
	while (*tmp)
	{
		if (*tmp != c && (!(tmp - s) || (*(tmp - 1) == c)))
			count++;
		tmp++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		num_words;

	if (!s)
		return (NULL);
	num_words = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * num_words + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < num_words)
	{
		j = 0;
		while (*s == c)
			s++;
		while (*(s + j) && *(s + j) != c)
			j++;
		res[i] = ft_strsub(s, 0, j);
		s += j;
		i++;
	}
	res[i] = 0;
	return (res);
}
