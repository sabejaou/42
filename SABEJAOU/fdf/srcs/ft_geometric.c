/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_geometric.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:13:50 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/24 02:03:16 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/fdf.h"

unsigned int	rgb_to_int(double r, double g, double b)
{
	unsigned int	color;

	color = 0;
	color += b;
	color += g * 256;
	color += r * 65536;
	return (color);
}

int	ft_color(int color)
{
	if (color)
		return (color);
	return (0xFFFFFF);
}

void	ft_drawline(t_general *infg, t_line *linedt, int color)
{
	double	deltax;
	double	deltay;
	double	pixelx;
	double	pixely;
	int		pixels;

	deltax = linedt->endx - linedt->beginx;
	deltay = linedt->endy - linedt->beginy;
	pixels = sqrt((deltax * deltax) + (deltay * deltay));
	pixely = linedt->beginy;
	pixelx = linedt->beginx;
	deltax /= pixels;
	deltay /= pixels;
	while (pixels)
	{
		mlx_pixel_put(infg->mlx, infg->win, pixelx, pixely, color);
		pixelx += deltax;
		pixely += deltay;
		--pixels;
	}
}
