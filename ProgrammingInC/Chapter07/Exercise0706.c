// Exercise 7.6
// Modify Program 7.8 so that the squareRoot() function accepts a double precision 
// argument and returns the result as a double precision value. Be certain to change 
// the value of the variable epsilon to reflect the fact that double precision 
// variables are now being used.

#include <stdio.h>

// Function to calculate the absolute value
double absoluteValue(double x)
{
	return x < 0 ? -x : x;
}

// Function to compute the square root of a number
double squareRoot(double x)
{
	const double epsilon = .00001f;
	double guess = 1.0;

	while (absoluteValue(guess * guess - x) >= epsilon)
	{
		guess = (x / guess + guess) / 2.0f;
	}

	return guess;
}

int main(void)
{
	printf("squareRoot (2.0) = %f\n", squareRoot(2.0));
	printf("squareRoot (144.0) = %f\n", squareRoot(144.0));
	printf("squareRoot (17.5) = %f\n", squareRoot(17.5));

	return 0;
}