# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:10:07 by sbejaoui          #+#    #+#              #
#    Updated: 2021/11/24 02:51:54 by sbejaoui         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS_PATH = srcs/

LIBS_PERSO = gnl/gnl.a \
			libft/libft.a

SRCS =  $(SRCS_PATH)window.c	   \
		$(SRCS_PATH)ft_geometric.c \
		$(SRCS_PATH)ft_parsing.c   \
		$(SRCS_PATH)ft_psone.c     \
		$(SRCS_PATH)ft_pstwo.c     \

OBJS = ${SRCS:.c=.o}

VERIF = -g3 -fsanitize=address

CC = gcc
RM = rm -f

%.o: %.c incl/fdf.h
	$(CC) -Imlx -c $< -o $@

$(NAME): $(OBJS) mlx lft 
	$(CC) -Llibmlx -lmlx -framework OpenGL -framework AppKit $(LIBS_PERSO) $(OBJS) -o $(NAME)
	
all: ${NAME} 

mlx :
	make -C libmlx

lft :
	make -C libft
	make -C gnl

clean:
	${RM} ${OBJS}
	make -C libmlx clean
	make -C libft fclean
	make -C gnl fclean

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re