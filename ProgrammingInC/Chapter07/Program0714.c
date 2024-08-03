// Program 7.14 - Using Multidimensional Arrays and Functions

#include <stdio.h>

#define MAX_COLUMNS 5

void scalarMultiply(int nRows, int nCols, int matrix[][MAX_COLUMNS], int scalar)
{
	int row, column;

	for (row = 0; row < nRows; ++row)
		for (column = 0; column < nCols; ++column)
			matrix[row][column] *= scalar;
}

void displayMatrix(int nRows, int nCols, int matrix[][MAX_COLUMNS])
{
	int row, column;

	for (row = 0; row < nRows; ++row)
	{
		for (column = 0; column < nCols; ++column)
			printf("%5i", matrix[row][column]);

		printf("\n");
	}
}

int main(void)
{
	int sampleMatrix[3][MAX_COLUMNS] =
	{
		{  7, 16, 55, 13, 12 },
		{ 12, 10, 52,  0,  7 },
		{ -2,  1,  2,  4,  9 }
	};

	printf("Original matrix:\n");
	displayMatrix(3, MAX_COLUMNS, sampleMatrix);

	scalarMultiply(3, MAX_COLUMNS, sampleMatrix, 2);

	printf("\nMultiplied by 2:\n");
	displayMatrix(3, MAX_COLUMNS, sampleMatrix);

	scalarMultiply(3, MAX_COLUMNS, sampleMatrix, -1);

	printf("\nThen multiplied by -1:\n");
	displayMatrix(3, MAX_COLUMNS, sampleMatrix);

	return 0;
}