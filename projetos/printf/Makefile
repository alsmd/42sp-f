SRCS = ./src/main.c ./src/ft_printf.c

OBJS = $(SRCS:.c=.o)

NAME = ft_printf

CFLAGS = 

CC = clang 

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	./$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)
.PHONY: all clean fclean re