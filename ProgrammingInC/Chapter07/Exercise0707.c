// Exercise 7.7
// Write a function that raises an integer to a positive integer power. Call the 
// function x_to_the_n() taking two integer arguments x and n. Have the function 
// return a long int, which represents the results of calculating x^n.

#include <stdio.h>

long int x_to_the_n(int x, int n)
{
	long int result = 1;

	for (int i = 0; i < n; i++)
	{
		result *= x;
	}

	return result;
}

void run_test(int x, int n, long int expected)
{
	long int actual = x_to_the_n(x, n);
	printf("x: %i, n : %i, expected: %ld, actual: %ld, %s\n", x, n, expected, actual, expected == actual ? "PASS" : "FAIL");
}

int main(void)
{
	run_test(2, 0, 1);
	run_test(2, 3, 8);
	run_test(3, 2, 9);
	run_test(5, 3, 125);
	run_test(10, 5, 100000);
	run_test(7, 2, 49);
	run_test(4, 4, 256);
	run_test(6, 3, 216);
	run_test(8, 2, 64);
	run_test(9, 3, 729);
	run_test(2, 10, 1024);
	run_test(1, 100, 1);

	return 0;
}