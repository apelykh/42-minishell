/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitspaceswithquotes.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 19:20:00 by apelykh           #+#    #+#             */
/*   Updated: 2017/10/04 19:20:01 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	return (c == '\t' || c == '\n' || c == ' ' || c == '\0');
}

static int	count_words(char **str)
{
	int in_quotes;

	in_quotes = 0;
	while (!is_space(**str) || (is_space(**str) && in_quotes))
	{
		if (**str == '\"' || **str == '\'')
			in_quotes = in_quotes == 0;
		(*str)++;
	}
	return (1);
}

static int	count_quotes(char *str, int n)
{
	int num_quotes;

	num_quotes = 0;
	while (*str && n > 0)
	{
		if (*str == '\"' || *str == '\'')
			num_quotes++;
		str++;
		n--;
	}
	return (num_quotes);
}

static void	skip_spaces(char **str)
{
	while (**str && is_space(**str))
		(*str)++;
}

char		**ft_strsplitspaceswithquotes(char *str)
{
	char	**split;
	char	*ptr;
	int		word;

	word = 0;
	ptr = str;
	while (*ptr)
	{
		skip_spaces(&ptr);
		word += count_words(&ptr);
		skip_spaces(&ptr);
	}
	split = ft_arrnew(word);
	word = 0;
	while (*str)
	{
		skip_spaces(&str);
		ptr = str;
		count_words(&str);
		split[word] = ft_strnew(str - ptr - count_quotes(ptr, str - ptr));
		ft_strncpywoutquotes(split[word], ptr, str - ptr);
		split[word++][str - ptr] = '\0';
		skip_spaces(&str);
	}
	return (split);
}
