/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 03:33:33 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/24 02:47:46 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libmlx/mlx.h"
# include "../libft/libft.h"
# include "../gnl/gnl.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define ERR "Mauvais input, verifiez le nombre d'arguments ou le format"

typedef struct s_general
{
	int		**tab;
	int		**tabcolor;
	int		scrw;
	int		scrh;
	int		x;
	int		y;
	void	*mlx;
	void	*win;
}	t_general;

typedef struct s_line
{
	int	beginx;
	int	beginy;
	int	endx;
	int	endy;
	int	espx;
	int	espy;
	int	cfy;
	int	cfny;
	int	tmpx;
	int	tmpy;
	int	ps;
	int	tmp;
}	t_line;

void			ft_drawisometricgrid(t_general	infg);
unsigned int	rgb_to_int(double r, double g, double b);
int				ft_color(int color);
void			ft_drawline(t_general *infg, t_line *linedt, int color);
int				**ft_txttotab(int fd, char *alire, t_general *infg);
int				**sizetab(char *alire, t_general *infg);
void			ft_initbeginpstwo(t_general *infg, t_line *linedt);
void			ft_changevaluespstwo(t_general *infg, t_line *linedt);
void			ft_initlinedt(t_line *linedt, t_general infg);
void			ft_tracepstwo(t_general infg, t_line linedt);
void			ft_tracepstwowhi(t_general infg, t_line linedt);
void			ft_changevaluespsone(t_general *infg, t_line *linedt);
void			ft_initbeginpsone(t_general *infg, t_line *linedt);
void			ft_tracepsone(t_general *infg, t_line *linedt);
void			ft_tracepsonewhi(t_general *infg, t_line *linedt);

#endif