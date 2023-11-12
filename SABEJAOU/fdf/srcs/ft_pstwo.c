/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstwo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 03:55:02 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/24 02:04:37 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_initbeginpstwo(t_general *infg, t_line *linedt)
{
	linedt->endx = linedt->beginx - linedt->espx;
	linedt->endy = linedt->tmp - linedt->espy;
	if (linedt->beginy == infg->scrw / 2.5
		|| linedt->beginy == (infg->scrh / 4)
		* 3.5 - (linedt->espy * linedt->ps))
		linedt->endy = linedt->beginy - linedt->espy;
	linedt->tmp = linedt->endy;
}

void	ft_changevaluespstwo(t_general *infg, t_line *linedt)
{
	linedt->ps++;
	infg->x++;
	linedt->beginx = infg->scrw / 2.5 + (linedt->espx * linedt->ps);
	linedt->beginy = (infg->scrh / 4) * 3.5 - (linedt->espy * linedt->ps);
}

void	ft_tracepstwo(t_general infg, t_line linedt)
{
	while (infg.x < linedt.tmpx)
	{
		infg.y = linedt.tmpy - 1;
		while (infg.y >= 0)
		{
			ft_initbeginpstwo(&infg, &linedt);
			if (infg.x && infg.y && infg.tab[infg.x - 1][infg.y] > 0)
				linedt.endy -= infg.tab[infg.x - 1][infg.y] * linedt.cfy;
			else if (infg.x && infg.y && infg.tab[infg.x - 1][infg.y] < 0)
				linedt.endy += infg.tab[infg.x - 1][infg.y] * linedt.cfny;
			if (linedt.beginy != (infg.scrh / 4)
				* 3.5 - (linedt.espy * linedt.ps)
				&& linedt.beginy != (infg.scrh / 4) * 3.5 && linedt.ps)
				ft_drawline(&infg, &linedt,
					ft_color(infg.tabcolor[infg.x][infg.y]));
			linedt.beginx = linedt.endx;
			linedt.beginy = linedt.endy;
			infg.y--;
		}
		ft_changevaluespstwo(&infg, &linedt);
	}
}
