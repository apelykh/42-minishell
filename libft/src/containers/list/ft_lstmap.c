/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelykh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 18:52:22 by apelykh           #+#    #+#             */
/*   Updated: 2016/12/13 18:52:22 by apelykh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;

	if (!lst || !f)
		return (NULL);
	new = (*f)(lst);
	lst = lst->next;
	while (lst)
	{
		ft_lstaddback(&new, (*f)(lst));
		lst = lst->next;
	}
	return (new);
}
