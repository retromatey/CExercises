// Exercise 10.7
// 
// Write a pointer version of the sort() function from Chapter 7, “Working with Functions.” 
// Be certain that pointers are exclusively used by the function, including index variables 
// in the loops.
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>
#include <stdbool.h>

// Original sort function from Chapter 7
//void sort(int a[], int n, bool sort_ascending)
//{
//	int i, j, temp;
//
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			bool swap = sort_ascending
//				? a[i] > a[j]
//				: a[i] < a[j];
//
//			if (swap)
//			{
//				temp = a[i];
//				a[i] = a[j];
//				a[j] = temp;
//			}
//		}
//	}
//}

void sort(int* aPtr, int n, bool sort_ascending)
{
	int temp;
	int* ptr1;
	int* ptr2;

	for (ptr1 = aPtr; ptr1 < aPtr + n; ptr1++)
	{
		ptr2 = ptr1 + 1;

		for (ptr2 = ptr1 + 1; ptr2 < aPtr + n; ptr2++)
		{
			bool swap = sort_ascending
				? *ptr1 > *ptr2
				: *ptr1 < *ptr2;

			if (swap)
			{
				temp = *ptr1;
				*ptr1 = *ptr2;
				*ptr2 = temp;
			}
		}
	}
}

void print_array(int array[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%i ", array[i]);

	printf("\n");
}

int main(void)
{
	int array[16] = { 34, -5, 6, 0, 12, 100, 56, 22, 44, -3, -9, 12, 17, 22, 6, 11 };

	printf("The array before the sort:\n");
	print_array(array, 16);

	sort(array, 16, true);

	printf("\n\nThe array after the sort:\n");
	print_array(array, 16);

	printf("\n");

	return 0;
}