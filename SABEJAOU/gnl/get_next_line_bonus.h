/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:41:47 by sbejaoui          #+#    #+#             */
/*   Updated: 2021/11/14 19:25:37 by sbejaoui         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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
size_t	ft_strlen(char *str);
int		ft_strchr(char *str, char to_find);

#endif