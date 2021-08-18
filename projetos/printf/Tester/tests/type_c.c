#include "../test.h"


void	type_c()
{
	title("Type c: ");
	char	buffer_1[1000];
	char	buffer_2[1000];
	int		r_1;
	int		r_2;

	/*Basic case*/
	/*----------1------------*/
	#define PARAM "hello %c", '1'
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
	#define PARAM "Some string %10cZ", 'A'
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
	#define PARAM "Some string %-10cZ", 'A'
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
	#define PARAM "Some string %0 0+0-##0-0-0--10.13cZ", 'A'
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
	#define PARAM "Some string % cZ", 'l'
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

	//////////////////////////////////
	//////////////////////////
	////////////////////////
	//reset test
	/*----------5------------*/
	#define PARAM "Caso normal:%c|\n", 'F'
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
	#undef PARAM	/*----------5------------*/
	#define PARAM "Caso normal:%c|\n", 'F'
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

	/*----------5------------*/
	#define PARAM "Caso com #:%#c|\n", 'F'
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

	/*----------5------------*/
	#define PARAM "Caso com espaço:% c|\n", 'F'
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

	/*----------5------------*/
	#define PARAM "Caso com +:%+c|\n", 'F'
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

	/*----------5------------*/
	#define PARAM "Caso com width 3:%3c|\n", 'F'
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

	/*----------5------------*/
	#define PARAM "Caso com width 3 e -:%-3c|\n", 'F'
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

	/*----------5------------*/
	#define PARAM "Caso com width 3 e 0:%03c|\n", 'F'
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

	/*----------5------------*/
	#define PARAM "Caso com width 3 e 0 e -:%-03c|\n", 'F'
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

	/*----------5------------*/
	#define PARAM " %c %c %c ", '0', 0, '1'
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
	putstr_fd("\n", 2);
}
