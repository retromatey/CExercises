// Exercise 7.15
//
// Modify Program 7.15 so that the user is asked again to type in the value of the base
// if an invalid base is entered. The modified program should continue to ask for the
// value of the base until a valid response is given.
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int convertedNumber[64];
long int numberToConvert;
int base;
int digit = 0;

void set_base(void)
{
	bool valid_base = false;

	while (!valid_base)
	{
		printf("Base? ");

		if (scanf("%i", &base) == 1)
		{
			if (base == 2 || base == 8 || base == 10 || base == 16)
			{
				printf("Convert %ld to base %i\n", numberToConvert, base);
				valid_base = true;
			}
			else
			{
				printf("Invalid base - must be 2, 8, 10, or 16\n");
			}
		}
		else
		{
			printf("Invalid base - must be 2, 8, 10, or 16\n");
			// Clear the input buffer
			int c;
			while ((c = getchar()) != '\n' && c != EOF);
		}
	}
}

void getNumberAndBase(void)
{
	printf("Number to be converted? ");

	if (scanf("%ld", &numberToConvert) == 1)
	{
		set_base();
	}
	else
	{
		printf("Invalid number entered\n");
		exit(1);
	}
}

void convertNumber(void)
{
	do
	{
		convertedNumber[digit] = numberToConvert % base;
		++digit;
		numberToConvert = numberToConvert / base;
	} while (numberToConvert != 0);
}

void displayConvertedNumber(void)
{
	const char baseDigits[16] =
	{
		'0', '1', '2', '3', '4', '5', '6', '7',
		'8', '9', 'A', 'B', 'C', 'D', 'E', 'F'
	};

	int nextDigit;

	printf("Converted number = ");

	for (--digit; digit >= 0; --digit)
	{
		nextDigit = convertedNumber[digit];
		printf("%c", baseDigits[nextDigit]);
	}

	printf("\n");
}

int main(void)
{
	getNumberAndBase();
	convertNumber();
	displayConvertedNumber();

	return 0;
}