#include <stdio.h>

// Function to calculate the absolute value
float  absoluteValue(float x)
{
    return x < 0 ? -x : x;
}

// Function to compute the square root of a number
float squareRoot(float x)
{
	const float epsilon = .00001f;
	float guess = 1.0;

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