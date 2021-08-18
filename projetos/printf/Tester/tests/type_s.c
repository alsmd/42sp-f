#include "../test.h"


void	type_s()
{
	title("Type s: ");
	char	buffer_1[1000];
	char	buffer_2[1000];
	int		r_1;
	int		r_2;

	/*Basic case*/
	/*----------1------------*/
	#define PARAM "hello %s", "World!"
	{
		bzero(buffer_1, 1000);
		bzero(buffer_2, 1000);
		redirect("tmp");
		r_1 = ft_printf(PARAM);
		lseek(1, 0, SEEK_SET);
		read(1, buffer_1, 1000);
		redirect("tmp2");
		r_2 = printf(PARAM);
		fflush(stdout);
		lseek(1, 0, SEEK_SET);
		read(1, buffer_2, 1000);
		/*1*/check(!(strcmp(buffer_1, buffer_2)));
		/*2*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM

	/*----------2------------*/
	#define PARAM "Some string %10sZ", "That will test my function"
	{
		bzero(buffer_1, 1000);
		bzero(buffer_2, 1000);
		redirect("tmp");
		r_1 = ft_printf(PARAM);
		lseek(1, 0, SEEK_SET);
		read(1, buffer_1, 1000);
		redirect("tmp2");
		r_2 = printf(PARAM);
		fflush(stdout);
		lseek(1, 0, SEEK_SET);
		read(1, buffer_2, 1000);
		/*3*/check(!(strcmp(buffer_1, buffer_2)));
		/*4*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM

	/*----------3------------*/
	#define PARAM "Some string %-10sZ", "random"
	{
		bzero(buffer_1, 1000);
		bzero(buffer_2, 1000);
		redirect("tmp");
		r_1 = ft_printf(PARAM);
		lseek(1, 0, SEEK_SET);
		read(1, buffer_1, 1000);
		redirect("tmp2");
		r_2 = printf(PARAM);
		fflush(stdout);
		lseek(1, 0, SEEK_SET);
		read(1, buffer_2, 1000);
		/*5*/check(!(strcmp(buffer_1, buffer_2)));
		/*6*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM

	/*----------4------------*/
	#define PARAM "Some string %0 0+0-0-0##-0--10.13sZ", "that I Wrote"
	{
		bzero(buffer_1, 1000);
		bzero(buffer_2, 1000);
		redirect("tmp");
		r_1 = ft_printf(PARAM);
		lseek(1, 0, SEEK_SET);
		read(1, buffer_1, 1000);
		redirect("tmp2");
		r_2 = printf(PARAM);
		fflush(stdout);
		lseek(1, 0, SEEK_SET);
		read(1, buffer_2, 1000);
		/*7*/check(!(strcmp(buffer_1, buffer_2)));
		/*8*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM

	/*----------4------------*/
	#define PARAM "Some string % sZ", "that I Wrote"
	{
		bzero(buffer_1, 1000);
		bzero(buffer_2, 1000);
		redirect("tmp");
		r_1 = ft_printf(PARAM);
		lseek(1, 0, SEEK_SET);
		read(1, buffer_1, 1000);
		redirect("tmp2");
		r_2 = printf(PARAM);
		fflush(stdout);
		lseek(1, 0, SEEK_SET);
		read(1, buffer_2, 1000);
		/*7*/check(!(strcmp(buffer_1, buffer_2)));
		/*8*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM

	putstr_fd("\n", 2);
}