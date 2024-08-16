// Exercise 7.10
//
// Write a function prime() that returns 1 if its argument is a prime number and returns 0 otherwise.
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>

int prime(int n)
{
	int result = 1;

	if (n == 1)
		result = 0;
	else if (n == 2 || n == 3)
		result = 1;
	else if (n % 2 == 0 || n % 3 == 0)
		result = 0;
	else
	{
		int half_n = n / 2;

		for (int i = 5; i < half_n; i++)
		{
			if (n % i == 0)
			{
				result = 0;
				break;
			}
		}
	}

	return result;
}

void test_runner(int n, int expected)
{
	int actual = prime(n);
	printf("n: %2i, expected: %i, actual: %i - %s\n",
		n, expected, actual, expected == actual ? "PASS" : "FAIL");
}

int main(void)
{
	test_runner(4, 0);
	test_runner(5, 1);
	test_runner(1, 0);  // 1 is not a prime number
	test_runner(2, 1);  // 2 is a prime number
	test_runner(3, 1);  // 3 is a prime number
	test_runner(6, 0);  // 6 is not a prime number
	test_runner(7, 1);  // 7 is a prime number
	test_runner(9, 0);  // 9 is not a prime number
	test_runner(11, 1); // 11 is a prime number
	test_runner(13, 1); // 13 is a prime number
	test_runner(15, 0); // 15 is not a prime number
	test_runner(17, 1); // 17 is a prime number
	test_runner(19, 1); // 19 is a prime number
	test_runner(20, 0); // 20 is not a prime number

	return 0;
}