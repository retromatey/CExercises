// Write a program to read a set of non-zero numbers into an array of maximum size 100. 
// Data is terminated by 0 and the amount of numbers is unknown beforehand. 
//  - find and print the largest; 
//  - find the sum of the numbers; 
//  - arrange the numbers in ascending order.

// Noel Kalicharan. C by Example (Cambridge Computer Science Texts) (Kindle Locations 577 - 579). Kindle Edition.

#include <stdio.h>

#define MAX_SIZE 100

int find_max(int* nums);
int get_sum(int* nums);
int order_ascending(int* nums);

int main(int argc, char* argv[])
{
	int numbers[MAX_SIZE] = { 0 };
	int index = 0;
	int input;

	while (fscanf(stdin, "%d", &input) == 1 && index < MAX_SIZE)
	{
		numbers[index] = input;
		index++;
		
		if (input == 0)
			break;
	}

	int max = find_max(numbers);
	int sum = get_sum(numbers);
	order_ascending(numbers);

	fprintf(stdout, "Largest number: %d\n", max);
	fprintf(stdout, "Sum of numbers: %d\n", sum);
	fprintf(stdout, "Numbers in ascending order:\n");
	for (int i = 0; i < MAX_SIZE && numbers[i] != 0; i++)
		fprintf(stdout, "%d ", numbers[i]);
	fprintf(stdout, "\n");

	return 0;
}

int find_max(int* nums)
{
	int result = nums[0];

	for (int i = 0; i < MAX_SIZE && nums[i] != 0; i++)
		if (nums[i] > result)
			result = nums[i];

	return result;
}

int get_sum(int* nums)
{
	int result = 0;

	for (int i = 0; i < MAX_SIZE && nums[i] != 0; i++)
		result += nums[i];

	return result;
}

int order_ascending(int* nums)
{
	int smallest = 0;
	int temp;

	for (int i = 0; i < MAX_SIZE - 1 && nums[i] != 0; i++)
	{
		smallest = i;

		for (int j = i + 1; j < MAX_SIZE && nums[j] != 0; j++)
			if (nums[smallest] > nums[j])
				smallest = j;

		temp = nums[i];
		nums[i] = nums[smallest];
		nums[smallest] = temp;
	}
}
