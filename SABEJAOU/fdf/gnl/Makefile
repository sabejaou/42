# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:10:07 by sbejaoui          #+#    #+#              #
#    Updated: 2021/11/19 22:39:18 by sbejaoui         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = gnl.a

SRCS =  get_next_line_utils.c \
		get_next_line.c


OBJS = ${SRCS:.c=.o}

CC = gcc
RM = rm -f

FLAGS = -Wall -Wextra -Werror

%.o : %.c gnl.h
	${CC} ${FLAGS} -I includes -c $< -o $@

$(NAME): ${OBJS} 
	ar rc ${NAME} ${OBJS} 

all: ${NAME} 

clean:
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean fclean re