FILES = ./utils/check.c ./utils/mcheck.c ./utils/title.c \
		../get_next_line.c ../get_next_line_utils.c \
		./tests/main.c ./tests/empty.c

OBJS = $(FILES:.c=.o)

INCLUDES = .

NAME = Tester

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -D BUFFER_SIZE=20

RM = rm -r

UNAME = $(shell uname -s)

ifeq ($(UNAME), Linux)
	VALGRIND = valgrind -q --leak-check=full
endif
all: run

$(NAME): $(OBJS)
	echo "\e[0;33m"
	$(CC) $(CFLAGS) -o $(NAME) ${OBJS}

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

run: $(NAME)
	$(VALGRIND) ./$(NAME)

.PHONY: run re fclean clean