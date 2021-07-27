FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c \
		ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
		ft_substr.c

OBJS = ${FILES:.c=.o}

NAME = libft

MAIN = main.c

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f
all: ${NAME}

${NAME}: ${OBJS}
	ar rc ${NAME}.a ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}.a

re: fclean all

run: ${MAIN:.c=.o}
	${CC} ${CFLAGS} -o ${NAME} ${MAIN:.c=.o}  -L. -lft -lbsd