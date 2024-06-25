// Write a program to read a set of non-zero numbers into an array of maximum size 100. Data is terminated 
// by 0 and the amount of numbers is unknown beforehand. 
//   - find and print the largest; 
//   - find the sum of the numbers; 
//   - arrange the numbers in ascending order.

// Noel Kalicharan. C by Example (Cambridge Computer Science Texts) (Kindle Locations 577 - 579). Kindle Edition.

#include <stdio.h>

#define MAX_NUMBERS 100

void read_numbers(int* numbers)
{
	int input;

	for (int i = 0; i < MAX_NUMBERS; i++)
	{
		if (scanf("%d", &input) == 1)
		{
			if (input == 0)
				break;

			numbers[i] = input;
		}
	}
}

int sum_numbers(int* numbers)
{
	int sum = 0;

	for (int i = 0; i < MAX_NUMBERS; i++)
		sum += numbers[i];

	return sum;
}

void order_ascending(int* numbers)
{
	int largest_index = 0;
	int temp;

	for (int i = 0; i < MAX_NUMBERS-1; i++)
	{
		for (int j = i+1; j < MAX_NUMBERS; j++)
			if (numbers[largest_index] < numbers[j])
				largest_index = j;

		temp = numbers[i];
		numbers[i] = numbers[largest_index];
		numbers[largest_index] = temp;
		largest_index = i + 1;
	}
}

int main(int argc, char* argv[])
{
	int numbers[MAX_NUMBERS] = { 0 };
	read_numbers(numbers);
	int sum = sum_numbers(numbers);
	order_ascending(numbers);

	return 0;
}
