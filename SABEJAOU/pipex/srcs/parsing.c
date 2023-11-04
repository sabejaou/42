/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 02:40:19 by sbejaoui          #+#    #+#             */
/*   Updated: 2022/01/20 09:34:36 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/pipex.h"

void	ft_parse(int argc, char **argv, t_cmd **fcmd, char **env)
{
	t_cmd	*tmp;
	int		i;

	i = 2;
	while (i < argc - 1)
	{
		ft_lstadd_back(fcmd, ft_lstnew(ft_split(argv[i], ' '), 0));
		i++;
	}
	tmp = *fcmd;
	if (tmp->cmd[0])
		tmp->path = pathcmd(env, tmp->cmd[0]);
	else
		tmp->path = NULL;
	if (tmp->next->cmd[0])
		tmp->next->path = pathcmd(env, tmp->next->cmd[0]);
	else
		tmp->next->path = NULL;
}
