#include <stdio.h>

// Write a program which requests the user to enter a number.  
// The number and the square of the number are then printed on the same line.  
// For example, if the user enters 6, the program should print: 
// Number = 6, Square of Number = 36.

int main()
{
	int input;
	int square;
	puts("Enter a number: ");
	scanf_s("%d", &input);
	square = input * input;
	printf("Number = %i Square of Number = %i\n", input, square);

	return 0;
}