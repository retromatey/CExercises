// Write a program to read a positive integer N and determine
// a) whether N is even or odd
// b) whether or not N is prime
// c) whether or not N is a perfect square

#include <stdio.h>
#include <stdbool.h>

bool isEven(int num)
{
	return num % 2 == 0;
}

bool isPrime(int num) 
{
	if (num <= 1) return false;
	if (num <= 3) return true;
	if (num % 2 == 0 || num % 3 == 0) return false;

	for (int i = 5; i * i <= num; i += 6) 
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return false;
	}

	return true;
}

int main()
{
	int n;
	printf("Enter a positive integer: ");
	scanf_s("%d", &n);

	// Determine if n is even or odd
	if (isEven(n))
		printf("%d is even\n", n);
	else
		printf("%d is odd\n", n);

	// Determine if n is prime
	if (isPrime(n))
		printf("%d is prime\n", n);
	else
		printf("%d is not prime\n", n);

	// Determine if n is a perfect square

	return 0;
}