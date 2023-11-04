/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:22:27 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/13 04:49:07 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_cmd	*ft_lstlast(t_cmd *lst)
{
	size_t	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
