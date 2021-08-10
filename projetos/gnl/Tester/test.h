#ifndef TEST_H
# define TEST_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "../get_next_line.h"
/*-------Cores-------*/
#define BLACK "\e[0;30m"
#define RED "\e[0;31m"
#define GREEN "\e[0;32m"
#define YELLOW "\e[0;33m"
#define BLUE "\e[0;34m"
#define PURPLE "\e[0;35m"
#define CYN "\e[0;36m"
#define WHITE "\e[0;37m"

/*-------Utils-------*/
void	check(short int codition);
void	mcheck(void	*ptr, size_t size);
void	title(char	*string);

/*-------Functions-------*/
void	empty();
#endif