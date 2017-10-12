/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 14:28:26 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/14 14:28:26 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen(t_list *lst)
{
	t_list	*tmp;
	size_t	len;

	len = 0;
	tmp = lst;
	if (lst)
		while (tmp)
		{
			len++;
			tmp = tmp->next;
		}
	return (len);
}
