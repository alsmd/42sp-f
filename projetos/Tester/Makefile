FILES = ./tests/ft_isalpha_tester.c ./tests/main.c ./utils/check.c ./utils/title.c \
		./tests/ft_isdigit_tester.c ./tests/ft_isalnum_tester.c ./tests/ft_isascii_tester.c \
		./tests/ft_isprint_tester.c ./tests/ft_toupper_tester.c \
		./tests/ft_tolower_tester.c ./tests/ft_memset_tester.c ./tests/ft_bzero_tester.c ./tests/ft_memcpy_tester.c \
		./tests/ft_memmove_tester.c ./tests/ft_memchr_tester.c ./tests/ft_memcmp_tester.c ./tests/ft_calloc_tester.c \
		./utils/mcheck.c ./tests/ft_strlen_tester.c ./tests/ft_strlcpy_tester.c ./tests/ft_strlcat_tester.c \
		./tests/ft_strchr_tester.c ./tests/ft_strrchr_tester.c ./tests/ft_strncmp_tester.c \
		./tests/ft_strnstr_tester.c ./tests/ft_atoi_tester.c ./tests/ft_strdup_tester.c ./tests/ft_substr_tester.c \
		./tests/ft_strjoin_tester.c ./tests/ft_strtrim_tester.c ./tests/ft_split_tester.c ./tests/ft_itoa_tester.c \
		./tests/ft_strmapi_tester.c ./tests/ft_striteri_tester.c ./tests/ft_putchar_fd_tester.c \
		./tests/ft_putstr_fd_tester.c ./tests/ft_putendl_fd_tester.c ./tests/ft_putnbr_fd_tester.c ./tests/ft_lstnew_tester.c \
		./tests/ft_lstadd_front_tester.c ./tests/ft_lstsize_tester.c ./tests/ft_lstlast_tester.c \
		./tests/ft_lstadd_back_tester.c ./tests/ft_lstdelone_tester.c ./tests/ft_lstclear_tester.c ./tests/ft_lstiter_tester.c \
		./tests/ft_lstmap_tester.c

OBJS = $(FILES:.c=.o)

INCLUDES = .

NAME = Tester

LIB_SOURCE = ../

CC = gcc

CFLAGS = -g 

RM = rm -fpwd

UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	VALGRIND = valgrind -q --leak-check=full
endif
all: run

$(NAME): make_lib $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) ${OBJS} -L$(LIB_SOURCE) -lft

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	$(VALGRIND) ./$(NAME)

make_lib:
	echo "\e[0;33m"
	make -C $(LIB_SOURCE)

.PHONY: run re fclean clean make_lib