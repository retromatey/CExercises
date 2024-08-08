// Exercise 7.8
// 
// An equation of the form
//
// ax^2 + bx + c = 0
// 
// is known as a quadratic equation.The values of a, b, and c in the preceding example represent 
// constant values. So
//
// 4x^2 - 17x - 15 = 0
//
// represents a quadratic equation where a = 4, b = -17, and c = -15. The values of x that satisfy 
// a particular quadratic equation, known as the roots of the equation, can be calculated by 
// substituting the values of a, b, and c into the following two formulas:
//
//     -b ± sqrt(b^2-4ac)
// x = ------------------
//             2a
//
// If the value of b^2 - 4ac, called the discriminant, is less than zero, the roots of the equation, 
// x1 and x2, are imaginary numbers.
//
// Write a program to solve a quadratic equation.The program should allow the user to enter the 
// values for a, b, and c. If the discriminant is less than zero, a message should be displayed 
// that the roots are imaginary; otherwise, the program should then proceed to calculate and 
// display the two roots of the equation. (Note: Be certain to make use of the squareRoot() 
// function that you developed in this chapter.)

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

	while (absoluteValue(guess * guess / x - 1) >= epsilon)
	{
		guess = (x / guess + guess) / 2.0f;
		//printf("\tguess = %.5f\n", guess);
	}

	return guess;
}

double get_discriminant(int a, int b, int c)
{
	return (double)((b * b) - 4 * a * c);;
}

void get_roots(int a, int b, int c, double* x1, double* x2)
{
	double discriminant = get_discriminant(a, b, c);

	if (discriminant < 0)
	{
		printf("The roots are imaginary\n");
	}
	else
	{
		*x1 = (-b + squareRoot(discriminant)) / (2 * a);
		*x2 = (-b - squareRoot(discriminant)) / (2 * a);
		printf("The roots are %.3f and %.3f\n", *x1, *x2);
	}
}

int main(void)
{
	double x1 = 0.0;
	double x2 = 0.0;
	get_roots(4, -17, -15, &x1, &x2);
	// TODO: make test cases and verify logic

	return 0;
}