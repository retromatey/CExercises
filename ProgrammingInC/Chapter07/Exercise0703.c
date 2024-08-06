// Exercise 7.3
// Modify Program 7.8 so that the value of epsilon is passed as an argument to the 
// function. Try experimenting with different values of epsilon to see the effect 
// that it has on the value of the square root.

#include <stdio.h>

// Function to calculate the absolute value
float  absoluteValue(float x)
{
	return x < 0 ? -x : x;
}

// Function to compute the square root of a number
float squareRoot(float x, float epsilon)
{
	float guess = 1.0;

	while (absoluteValue(guess * guess - x) >= epsilon)
	{
		guess = (x / guess + guess) / 2.0f;
	}

	return guess;
}

int main(void)
{
	//printf("squareRoot (2.0) = %f\n", squareRoot(2.0));
	printf("squareRoot (144.0) = %f\n", squareRoot(144.0, 0.00001f));
	printf("squareRoot (144.0) = %f\n", squareRoot(144.0, 0.0001f));
	printf("squareRoot (144.0) = %f\n", squareRoot(144.0, 0.001f));
	printf("squareRoot (144.0) = %f\n", squareRoot(144.0, 0.01f));
	printf("squareRoot (144.0) = %f\n", squareRoot(144.0, 0.1f));
	//printf("squareRoot (17.5) = %f\n", squareRoot(17.5));

	return 0;
}