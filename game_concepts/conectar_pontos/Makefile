SRCS =	main.c pixel_manipulation.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

CFLAGS		= -g
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

CC = clang

RM = rm -f

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
	make -C mlx
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

run: $(NAME)
	./$(NAME)

re: fclean all