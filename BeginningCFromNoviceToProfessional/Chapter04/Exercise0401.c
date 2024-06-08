// Write a program that will generate a multiplication table of a size entered 
// by the user. A table of size 4, for instance, would have four rows and four 
// columns. The rows and columns would be labeled from 1 to 4. Each cell in the 
// table will contain the product of the corresponding row and column numbers, 
// so the value in the position corresponding to the third row and the fourth 
// column would contain 12.

#include <stdio.h>

int main() 
{
	int size;
	printf("Enter the size of the multiplication table: ");
	scanf_s("%d", &size);

	for (int i = 0; i <= size; i++)
	{
		for (int j = 0; j <= size; j++)
		{
			int cellValue = 0;

			if (i == 0)			// Print row labels
				cellValue = j;
			else if (j == 0)	// Print column label
				cellValue = i;
			else				// Print cell value
				cellValue = i * j;

			if (j == 0 && i == 0)
				printf("    ");
			else
				printf("%3d ", cellValue);
		}

		printf("\n");
	}

	return 0;
}