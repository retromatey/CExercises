// Write a program to read a positive integer N and determine
// a) whether N is even or odd
// b) whether or not N is prime
// c) whether or not N is a perfect square

#include <stdio.h>

int main()
{
	int n;
	printf("Enter a positive integer: ");
	scanf_s("%d", &n);

	if (n % 2 == 0)
		printf("%d is even\n", n);
	else
		printf("%d is odd\n", n);

	// Determine if n is prime

	// Determine if n is a perfect square

	return 0;
}