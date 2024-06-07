// Write a program which requests the user to enter a number.  
// The number and the square of the number are then printed on the same line.  
// For example, if the user enters 6, the program should print: 
// Number = 6, Square of Number = 36.

// Modify the logic above so that the user can enter as many numbers as required (but one at a time).
// For each, the number and its square are printed.  When the user wishes to stop, 0 is entered.
// The following is a sample run:
// 
// Enter a number: 5
// Number = 5, Square of Number = 25
// Enter a number: 7
// Number = 7, Square of Number = 49
// Enter a number: 0
// *** End of Session ***


#include <stdio.h>

int main() 
{
	int input;

	do
	{
		printf("Enter a number: ");
		scanf_s("%d", &input);

		if (input != 0)
		{
			printf("Number = %d, Square of Number = %d\n", input, input * input);
		}
	} while (input != 0);

	puts("*** End of Session ***");

	return 0;
}