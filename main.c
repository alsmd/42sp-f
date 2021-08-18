#include <stdio.h>
# include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<fcntl.h>
#include <sys/stat.h>
/* int	d(void)
{

	//d
	printf("Caso normal:%d|\n", 10);
	printf("Com #:%#d|\n", 10);
	printf("Com espaço:% d|\n", 10);
	printf("Com +:%+d|\n", 10);
	printf("Com + e espaço:% +d|\n", 10);
	printf("Com + e width 3:%+3d|\n", 10);
	/////////////////
	printf("Com espaço e width 3:% 3d|\n", 10);// primeiro ele faz o espço, e espaço passa ser parte de width
	/////////////////
	printf("Com width 5:%5d|\n", 10);
	printf("Com width 5 e -:%-5d|\n", 10);
	printf("Com width 5 e 0:%05d|\n", 10);
	printf("Com width 5 e - e 0:%-05d|\n", 10);
	printf("Com . com size 5:%.5d|\n", 10);
	printf("Com width 7 e com . com size 5:%7.5d|\n", 10);
	printf("Com width 7 e - com . com size 5:%-7.5d|\n", 10);
	printf("Com width 7 e 0 com . com size 5:%07.5d|\n", 10);
	return (0);
}
 */
/* int	c(void)
{
	printf("Caso normal:%c|\n", 'F');
	printf("Caso com #:%#c|\n", 'F');
	printf("Caso com espaço:% c|\n", 'F');
	printf("Caso com +:%+c|\n", 'F');
	printf("Caso com width 3:%3c|\n", 'F');
	printf("Caso com width 3 e -:%-3c|\n", 'F');
	printf("Caso com width 3 e 0:%03c|\n", 'F');
	printf("Caso com width 3 e 0 e -:%-03c|\n", 'F');
	/////////////////////////////////////////////////
	return (0);
} */
void	test(int a, ...)
{
	va_list ptr;
	char	c;

	va_start(ptr, a);
	c = va_arg(ptr, int);
	printf("%c", c);
}
int	main(void)
{
	int teste;

	printf("");
	return (0);
}