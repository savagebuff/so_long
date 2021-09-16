/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: choney <choney@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 01:25:02 by choney            #+#    #+#             */
/*   Updated: 2021/07/30 01:25:03 by choney           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;

	tmp = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			while (tmp)
			{
				new = tmp->next;
				(*del)(tmp->content);
				free(tmp);
				tmp = new;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&tmp, new);
		lst = lst->next;
	}
	return (tmp);
}
