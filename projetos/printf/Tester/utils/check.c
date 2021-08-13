#include "../test.h"

void	check(short int codition)
{
	if (codition)
		printf("%s OK %s", GREEN, WHITE);
	else
		printf("%s KO %s", RED, WHITE);
}
