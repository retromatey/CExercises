// Write a program that acts as a simple "printing" calculator. The program should 
// allow the user to type in expressions of the form 
// number      operator 
// The following operators should be recognized by the program: 
// +      -      *      /      S      E
// The S operator tells the program to set the "accumulator" to the typed-in number.
// The E operator tells the program that execution is to end. The arithmetic operations 
// are performed on the contents of the accumulator with the number that was keyed in 
// acting as the second operand. The following is a “sample run” showing how the program 
// should operate:
// 
// Begin calculations
// 10 S
// = 10.000000
// 2 /
// = 5.000000
// 55 -
// = -50.000000
// 100.25 S
// = 100.250000
// 4 *
// = 401.000000
// 0 E
// End of calculations

// Make certain that the program detects division by zero and also checks for unknown operators.

// Kochan, Stephen G. Programming in C (p. 171). Pearson Education. Kindle Edition.

#include <stdio.h>
#include <stdlib.h>

// ********************************************************************
// 
// Handle TODOs
// Review code, try to generate an AI version
// 
// Come up with some additional test cases
// 
// ********************************************************************

int main()
{
	float accumulator = 0.0F;
	char input_operator = ' ';
	float input_number = 0.0F;

	printf("Begin calculations\n");

	while (input_operator != 'E')
	{
		if (scanf("%f %c", &input_number, &input_operator) > 0)
		{
			switch (input_operator)
			{
				case 'S':
					accumulator = input_number;
					break;
				case '+':
					accumulator += input_number;
					break;
				case '-':
					accumulator -= input_number;
					break;
				case '*':
					accumulator *= input_number;
					break;
				case '/':
					accumulator /= input_number;	// TODO: check for zero division first
					break;
				case 'E':
					break;
				default:
					printf("Invalid input operator detected\n");
					exit(1);
					break;
			}
			printf("= %f\n", accumulator);	// TODO: don't print if 'E' has been input to end the program
		}
		else
		{
			printf("Invalid input detected\n");
			exit(1);
		}
	}

	printf("End of calculations\n");

	return 0;
}