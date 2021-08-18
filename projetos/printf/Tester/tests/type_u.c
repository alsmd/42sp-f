#include "../test.h"


void	type_u_tester()
{
	title("Type u: ");
	char	buffer_1[1000];
	char	buffer_2[1000];
	int		r_1;
	int		r_2;

	/*Basic case*/
	/*----------1------------*/
	#define PARAM "hello %d", 0x13f
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
	#define PARAM "Some string %10uZ", 41203901
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
	#define PARAM "Some string %-10uZ",  -41203901
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
	#define PARAM "Some string %0 0+0-0-0##-0--10.13uZ",  41203901
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
	/*----------5------------*/
	#define PARAM "Some string % uZ",  -41203901
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
		/*9*/check(!(strcmp(buffer_1, buffer_2)));
		/*10*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM
	/*----------6------------*/
	#define PARAM "Some string %010uZ",  41203901
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
		/*11*/check(!(strcmp(buffer_1, buffer_2)));
		/*12*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM	/*----------6------------*/
	#define PARAM "Some string %015.12uZ",  41203901
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
		/*11*/check(!(strcmp(buffer_1, buffer_2)));
		/*12*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM

	/*----------7------------*/
	#define PARAM "Some string %015.12uZ",  41203901
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
		/*13*/check(!(strcmp(buffer_1, buffer_2)));
		/*14*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM

	/*----------8------------*/
	#define PARAM "Some string %0-15.12uZ", 41203901
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
		/*15*/check(!(strcmp(buffer_1, buffer_2)));
		/*16*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM

	/*----------9------------*/
	#define PARAM "Some string %#0-15.12uZ", 41203901
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
		/*17*/check(!(strcmp(buffer_1, buffer_2)));
		/*18*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM

	/*----------10------------*/
	#define PARAM "Some string %# +uZ", 41203901
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
		/*18*/check(!(strcmp(buffer_1, buffer_2)));
		/*19*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM

	/*----------11------------*/
	#define PARAM "Some string % uZ",  41203901
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
		/*20*/check(!(strcmp(buffer_1, buffer_2)));
		/*21*/check(r_1 == r_2);
		unlink("tmp");
		unlink("tmp2");
	}
	#undef PARAM
	putstr_fd("\n", 2);
}