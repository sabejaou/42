/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:41:47 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/24 01:21:45 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif

char	*get_next_line(int fd);
char	*ft_strealloc(char *src, int n);
char	*ft_strcat(char *dest, char *src, int size);
size_t	ft_strclen(char *str);
int		ft_strichr(char *str, char to_find);

#endif