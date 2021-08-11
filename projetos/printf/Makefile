SRCS = ./main.c ./src/ft_printf.c ./src/verify_format.c

OBJS = $(SRCS:.c=.o)

NAME = ft_printf

CFLAGS = 

CC = clang 

RM = rm -f

LIB_SOURCE = ./libft

all: $(NAME)

$(NAME): make_lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L$(LIB_SOURCE) -lft

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	./$(NAME)

make_lib:
	make -C $(LIB_SOURCE)

lib_fclean:
	make fclean -C $(LIB_SOURCE)

.PHONY: all clean fclean re make_lib lib_fclean