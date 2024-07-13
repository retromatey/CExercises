// Exercise 9-1. A function with the prototype double power(double x, int n); should calculate and 
// return the value of x^n. That is, the expression power(5.0, 4) will evaluate 5.0 * 5.0 * 5.0 * 5.0, 
// which will result in the value 625.0. Implement the power() function as a recursive function 
// (so it should call itself) and demonstrate its operation with a suitable version of main().

// Ivor Horton. Beginning C : From Novice to Professional, Fourth Edition (p. 372). Kindle Edition.


#include <stdio.h>

double power(double x, int n)
{
	return n == 0 ? 1 : x * power(x, --n);
}

void power_test(double x, int n, double expected_value, double (*test_fn)(double, int))
{
	double actual_value = test_fn(x, n);
	char* result = expected_value == actual_value ? "PASS" : "FAIL";

	printf("x: %.4f n: %i - expected: %.4f - actual - %.4f - %s\n",
		x, n, expected_value, actual_value, result);
}

int main(int argc, char *argv[])
{
	power_test(5.0, 4, 625.0, power);
	power_test(2.0, 3, 8.0, power);
	power_test(10.0, 2, 100, power);
	power_test(3.0, 3, 27, power);
	power_test(1.5, 4, 5.0625, power);
	power_test(0.5, 2, 0.25, power);

	return 0;
}