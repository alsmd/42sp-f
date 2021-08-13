#include "../test.h"

void	type_c()
{
	title("Type c:");

	/*Basic case*/
	printf("%c", 'c') == printf("%c", 'c');
	check();

	printf("\n");
}