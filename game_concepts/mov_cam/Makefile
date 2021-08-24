# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flavio <flavio@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 22:58:48 by mahautlat         #+#    #+#              #
#    Updated: 2021/08/21 14:18:09 by flavio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ./src/main.c ./src/pixel_manipulation.c ./src/make_ash.c ./src/actions.c ./src/map.c

SRCS_BONUS = 

SRCS_MANDATORY = ./game.c

OBJS 		= ${SRCS:.c=.o}
OBJS_B		= ${SRCS_BONUS:.c=.o}
OBJS_M		= ${SRCS_MANDATORY:.c=.o}

UNAME		:= $(shell uname)

PATH_MLX	= mlx
CC 			= gcc -g 
CFLAGS		= 
RM			= rm -f
NAME		= game
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
			make -C $(PATH_MLX)
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

bonus:		${OBJS} ${OBJS_B}
			make -C $(PATH_MLX)
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${OBJS_B} $(FLAGS)

clean:
			make -C $(PATH_MLX) clean
			${RM} ${OBJS} ${OBJS_M} ${OBJS_B}

fclean: 	clean
			make -C $(PATH_MLX) clean
			${RM} ${NAME}

re: 		fclean all

.PHONY:		bonus all clean fclean re