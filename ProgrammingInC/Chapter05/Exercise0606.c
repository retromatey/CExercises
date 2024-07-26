// Write a program that takes an integer keyed in from the terminal and extracts and 
// displays each digit of the integer in English. So, if the user types in 932, the 
// program should display:
//   nine three two 
// Remember to display “zero” if the user types in just a 0.

// Kochan, Stephen G. Programming in C (p. 172). Pearson Education. Kindle Edition.


#include <stdio.h>

void print_num_as_str(int n)
{
	char n_str[20];

	switch (n)
	{
	case 0:
		sprintf_s(n_str, sizeof(n_str), "zero");
		break;
	case 1:
		sprintf_s(n_str, sizeof(n_str), "one");
		break;
	case 2:
		sprintf_s(n_str, sizeof(n_str), "two");
		break;
	case 3:
		sprintf_s(n_str, sizeof(n_str), "three");
		break;
	case 4:
		sprintf_s(n_str, sizeof(n_str), "four");
		break;
	case 5:
		sprintf_s(n_str, sizeof(n_str), "five");
		break;
	case 6:
		sprintf_s(n_str, sizeof(n_str), "six");
		break;
	case 7:
		sprintf_s(n_str, sizeof(n_str), "seven");
		break;
	case 8:
		sprintf_s(n_str, sizeof(n_str), "eight");
		break;
	case 9:
		sprintf_s(n_str, sizeof(n_str), "nine");
		break;
	default:
		sprintf_s(n_str, sizeof(n_str), "unknown");
		break;
	}

	printf("%s ", n_str);
}

void print_nums(int n, int step)
{
	if (step == 0 && n == 0)
	{
		print_num_as_str(n);
	}
	else if (step >= 0 && n != 0)
	{
		int single_digit = n % 10;
		print_nums(n / 10, (step + 1));
		print_num_as_str(single_digit);
	}
}

int main() 
{
	int n;
	int step = 0;

	printf("Enter a number: ");
	scanf_s("%d", &n);
	print_nums(n, step);

	return 0;
}


// Alternative solution (without recursion)
//int main()
//{
//	int n;
//	int divisor = 1;
//	int digit;
//
//	printf("Enter a number: ");
//	scanf_s("%d", &n);
//
//	while (n / divisor > 9)
//		divisor *= 10;
//
//	while (divisor > 0)
//	{
//		digit = n / divisor;
//		n %= divisor;
//		divisor /= 10;
//		print_num_as_str(digit);
//	}
//
//	return 0;
//}