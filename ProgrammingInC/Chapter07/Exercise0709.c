// Exercise 7.9

// The least common multiple (lcm) of two positive integers u and v is the smallest 
// positive integer that is evenly divisible by both u and v. Thus, the lcm of 15 
// and 10, written lcm (15, 10), is 30 because 30 is the smallest integer divisible 
// by both 15 and 10. Write a function lcm() that takes two integer arguments and 
// returns their lcm. The lcm() function should calculate the least common multiple 
// by calling the gcd() function from Program 7.6 in accordance with the following 
// identity:
//
// lcm (u, v) = uv / gcd (u, v)        u, v >= 0

#include <stdio.h>

// Returns the greatest common divisor of two nonnegative integer values. 
int gcd(int u, int v)
{
	int temp;

	while (v != 0) {
		temp = u % v;
		u = v;
		v = temp;
	}

	return u;
}

int lcm(int u, int v)
{
	return (u * v) / gcd(u, v);
}

void test_runner(int u, int v, int expected_lcm)
{
	int actual_lcm = lcm(u, v);
	printf("u: %2i, v: %2i, expected: %3i, actual: %3i - %s\n",
		u, v, expected_lcm, actual_lcm, expected_lcm == actual_lcm ? "PASS" : "FAIL");
}

int main(void)
{
	test_runner(10, 15, 30);
	test_runner(21, 6, 42);
	test_runner(8, 9, 72);
	test_runner(14, 5, 70);
	test_runner(7, 3, 21);
	test_runner(12, 15, 60);
	test_runner(9, 10, 90);
	test_runner(25, 20, 100);
	test_runner(11, 13, 143);
	test_runner(18, 24, 72);
	test_runner(16, 20, 80);

	return 0;
}