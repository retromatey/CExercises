// Program 7.17 - Calculating Factorials Recursively

#include <stdio.h>

unsigned long int factorial(unsigned int n)
{
	unsigned long int result;

	if (n == 0)
		result = 1;
	else
		result = n * factorial(n - 1);

	return result;
}

int main(void)
{
	unsigned int j;

	for (j = 0; j < 11; ++j)
		printf("%2u! = %lu\n", j, factorial(j));

	return 0;
}