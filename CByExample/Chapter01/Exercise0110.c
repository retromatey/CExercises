// Write a program to request a temperature in Celsius and convert it to Fahrenheit.
// Modify the program to convert several temperatures.  Perform conversions until the
// 'rogue' value -999 is entered.
// Use the formula: F = (9/5)C + 32

#include <stdio.h>

int main()
{
	float celsius_input;

	do
	{
		printf("Enter a temperature in Celsius: ");
		scanf_s("%f", &celsius_input);

		if (celsius_input != -999)
		{
			float fahrenheit = (9.0 / 5.0) * celsius_input + 32;
			printf("Celsius: %.2f, Fahrenheit: %.2f\n", celsius_input, fahrenheit);
		}
	} while (celsius_input != -999);

	return 0;
}