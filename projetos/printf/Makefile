SRCS = ./src/ft_printf.c ./src/verify_format.c ./src/store_info.c ./src/print_param.c \
		./types/type_%.c ./types/type_d_i_u.c ./types/type_s_c.c ./types/type_p_x.c ./types/utils.c \
		./types/itoa_un.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CFLAGS = 

CC = clang 

RM = rm -f

LIB_SOURCE = ./libft

MAIN = main.c

all: $(NAME)

$(NAME): make_lib $(OBJS)
	cp $(LIB_SOURCE)/libft.a ./$(NAME)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME) $(MAIN:.c=.o)
	$(CC) $(CFLAGS) -o a.out $(MAIN:.c=.o)  -L. -lftprintf
	./a.out

make_lib:
	make -C $(LIB_SOURCE)

lib_fclean:
	make fclean -C $(LIB_SOURCE)

.PHONY: all clean fclean re make_lib lib_fclean