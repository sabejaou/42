/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_psone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 03:53:54 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/24 02:04:06 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

void	ft_changevaluespsone(t_general *infg, t_line *linedt)
{
		linedt->ps++;
		infg->y--;
		linedt->beginx = infg->scrw / 2.5 - (linedt->espx * linedt->ps);
		linedt->beginy = (infg->scrh / 4) * 3.5 - (linedt->espy * linedt->ps);
}

void	ft_initbeginpsone(t_general *infg, t_line *linedt)
{
	linedt->endx = linedt->beginx + linedt->espx;
	linedt->endy = linedt->tmp - linedt->espy;
	if (linedt->beginy == infg->scrw / 2.5
		|| linedt->beginy == (infg->scrh / 4)
		* 3.5 - (linedt->espy * linedt->ps))
		linedt->endy = linedt->beginy - linedt->espy;
	linedt->tmp = linedt->endy;
}

void	ft_initlinedt(t_line *linedt, t_general infg)
{
	(linedt->ps) = 0;
	(linedt->tmpy) = infg.y;
	(linedt->tmpx) = infg.x;
	(linedt->beginx) = infg.scrw / 2.5;
	(linedt->beginy) = (infg.scrh / 4) * 3.5;
	(linedt->cfy) = 6;
	(linedt->cfny) = -6;
	if (infg.x > 50)
		(linedt->espx) = (((linedt->beginx) / 2) * 3 / infg.x);
	else
		(linedt->espx) = (((linedt->beginx) / 2) * 1.5 / infg.x);
	(linedt->espy) = (linedt->espx) / 2;
	if (infg.x >= 100)
	{
		(linedt->cfy) = 2;
		(linedt->cfny) = -2;
		(linedt->espy) = 2;
		(linedt->espx) = 4;
	}
	if (infg.x >= 500)
	{
		(linedt->espy) = 1;
		(linedt->espx) = 2;
	}
}

void	ft_tracepsone(t_general *infg, t_line *linedt)
{
	while (infg->y >= 0)
	{
		infg->x = 0;
		while (infg->x < linedt->tmpx)
		{
			ft_initbeginpsone(infg, linedt);
			if (infg->tab[infg->x][infg->y] > 0)
			linedt->endy -= infg->tab[infg->x][infg->y] * linedt->cfy;
			else if (infg->tab[infg->x][infg->y] < 0)
				linedt->endy += infg->tab[infg->x][infg->y] * linedt->cfny;
			if (linedt->beginy != (infg->scrh / 4)
				* 3.5 - (linedt->espy * linedt->ps)
				&& linedt->beginy != (infg->scrh / 4) * 3.5 && linedt->ps)
				ft_drawline(infg, linedt,
					ft_color(infg->tabcolor[infg->x][infg->y]));
			linedt->beginx = linedt->endx;
			linedt->beginy = linedt->endy;
			infg->x++;
		}
		ft_changevaluespsone(infg, linedt);
	}
}
