#include <stdio.h>

void exchange(int* const pint1, int* const pint2)
{
	int temp;

	temp = *pint1;
	*pint1 = *pint2;
	*pint2 = temp;
}

int main(void)
{
	int i1 = -5;
	int i2 = 66;
	int* p1 = &i1;
	int* p2 = &i2;

	printf("i1 = %i, i2 = %i\n", i1, i2);	// -5, 66

	exchange(p1, p2);
	printf("i1 = %i, i2 = %i\n", i1, i2);	// 66, -5

	exchange(&i1, &i2);
	printf("i1 = %i, i2 = %i\n", i1, i2);	// -5, 66

	return 0;
}