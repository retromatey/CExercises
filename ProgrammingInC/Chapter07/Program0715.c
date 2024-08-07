// Program 7.15 Converting a Positive Integer to Another Base

#include <stdio.h>
#include <stdlib.h>

int convertedNumber[64];
long int numberToConvert;
int base;
int digit = 0;

void getNumberAndBase(void)
{
	printf("Number to be converted? ");

	if (scanf("%ld", &numberToConvert) == 1)
	{
		printf("Base? ");

		if (scanf("%i", &base) == 1)
		{
			if (base == 2 || base == 8 || base == 10 || base == 16)
			{
				printf("Convert %ld to base %i\n", numberToConvert, base);
			}
			else
			{
				printf("Invalid base - must be 2, 8, 10, or 16\n");
				exit(1);
			}
		}
		else
		{
			printf("Invalid base entered\n");
			exit(1);
		}
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