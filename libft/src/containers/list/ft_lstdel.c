/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:10:48 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/12 17:10:48 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *tmp_next;

	if (alst && *alst && del)
	{
		tmp = *alst;
		tmp_next = NULL;
		while (tmp)
		{
			(*del)((tmp)->content, (tmp)->content_size);
			tmp_next = (tmp)->next;
			(tmp)->next = NULL;
			free(tmp);
			tmp = tmp_next;
		}
		*alst = NULL;
	}
}
