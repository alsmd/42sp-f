#include "../test.h"


void	type_percent_tester()
{
	title("Type %: ");
	char	buffer_1[1000];
	char	buffer_2[1000];
	int		r_1;
	int		r_2;

	/*Basic case*/
	/*----------1------------*/
	#define PARAM "hello %%"
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
	#define PARAM "Some string %----+++++++#### 10%Z"
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

	/*---------3------------*/
	#define PARAM "Some string %%%%%%%%%%%%%%%%Z"
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
	
	putstr_fd("\n", 2);
}