// Exercise 10.8
// 
// Write a function called sort3() to sort three integers into ascending order. (This 
// function is not to be implemented with arrays.)
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>

void sort3(int* a, int* b, int* c)
{
	int temp;

	if (*a > *c)
	{
		temp = *a;
		*a = *c;
		*c = temp;
	}

	if (*b > *c)
	{
		temp = *b;
		*b = *c;
		*c = temp;
	}

	if (*a > *b)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}

void test(int a, int b, int c)
{
	printf("\n**********************************************\n");
	printf("Before: [%i, %i, %i]\n", a, b, c);
	sort3(&a, &b, &c);
	printf("After:  [%i, %i, %i]\n", a, b, c);
}

int main(void)
{
	test(3, 2, 1);
	test(3, 1, 2);
	test(2, 3, 1);
	test(2, 1, 3);
	test(1, 3, 2);
	test(1, 2, 3);

	return 0;
}