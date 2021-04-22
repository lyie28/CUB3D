# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 15:28:45 by lyie              #+#    #+#              #
#    Updated: 2021/04/21 14:46:45 by lyie             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard ./parsing/*.c) $(wildcard ./mlx/*.c)

OBJS = ${SRCS:.c=.o}

INC = -I./includes

NAME = cub3D

CC = clang -Wall -Wextra -Werror -g3
RM = rm -f

.c.o:
	${CC} ${INC} -c $< -o ${<:.c=.o}

$(NAME) : ${OBJS}
	${CC} ${INC} ${OBJS} -L ./minilibx-linux -lmlx -lX11 -lXext -lm -o ${NAME}

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
