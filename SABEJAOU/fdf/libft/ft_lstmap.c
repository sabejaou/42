/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 21:39:15 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/06 22:33:21 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*fl;

	fl = NULL;
	while (lst)
	{	
		new = ft_lstnew(f(lst->content));
		if (!new->content)
			del(new->content);
		lst = lst->next;
		ft_lstadd_back(&fl, new);
	}
	return (fl);
}
