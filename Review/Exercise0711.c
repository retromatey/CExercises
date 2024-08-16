// Exercise 7.11
//
// Write a function called arraySum() that takes two arguments: an integer
// array and the number of elements in the array. Have the function return
// as its result the sum of the elements in the array.
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>

int arraySum(int numbers[], int length)
{
	int result = 0;

	for (int i = 0; i < length; i++)
	{
		result += numbers[i];
	}

	return result;
}

void test_runner(int numbers[], int length, int expected)
{
	int actual = arraySum(numbers, length);
	printf("expected: %i, actual: %i - %s\n", expected, actual, expected == actual ? "PASS" : "FAIL");
}

int main(void)
{
	int test_01[] = { 1, 2, 3 };
	int length = 3;
	int expected = 6;
	test_runner(test_01, length, expected);

	int test_02[] = { 1, 1, 1, 1 };
	length = 4;
	expected = 4;
	test_runner(test_02, length, expected);

	int test_03[] = { -1, -2, -3, -4 };
	length = 4;
	expected = -10;
	test_runner(test_03, length, expected);

	int test_04[] = { 0, 0, 0, 0, 0 };
	length = 5;
	expected = 0;
	test_runner(test_04, length, expected);

	int test_05[] = { 100, 200, 300 };
	length = 3;
	expected = 600;
	test_runner(test_05, length, expected);

	return 0;
}