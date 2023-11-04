# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbejaoui <sbejaoui@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/06 20:10:07 by sbejaoui          #+#    #+#              #
#    Updated: 2022/01/22 20:32:27 by sbejaoui         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAMEB = pipex_bonus

SRCS_PATH = srcs/
SRCSB_PATH = srcsbns/

LIBS_PERSO = libft/libft.a

SRCS =  $(SRCS_PATH)main.c \
		$(SRCS_PATH)parsing.c \
		$(SRCS_PATH)pathing.c

BNS =  $(SRCSB_PATH)main_bonus.c \
		$(SRCSB_PATH)parsing_bonus.c \
		$(SRCSB_PATH)pathing_bonus.c

OBJS = ${SRCS:.c=.o}
OBJSB = ${BNS:.c=.o}

VERIF = -Wall -Wextra -Werror

CC = gcc
RM = rm -f

all: libs ${NAME} 

bonus: libs $(NAMEB)

%.o: %.c incl/pipex.h
	$(CC) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(VERIF) $(LIBS_PERSO) $(OBJS) -o $(NAME)
	
$(NAMEB): $(OBJSB)
	$(CC) $(VERIF) $(LIBS_PERSO) $(OBJSB) -o $(NAMEB)
	
libs:
	${MAKE} -C libft

clean:
	${RM} ${OBJS} ${OBJSB}
	make -C libft fclean

fclean:	clean
	${RM} ${NAME}

re:	fclean all
         
.PHONY: all clean libs bonus fclean re