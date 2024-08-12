// Exercise 7.12
//
// A matrix M with i rows, j columns can be transposed into a matrix N having j rows 
// and i columns by simply setting the value of N[a,b] equal to the value of M[b,a] for 
// all relevant values of a and b.
//
// a. Write a function transposeMatrix() that takes as an argument a 4 × 5 matrix and 
//    a 5 × 4 matrix. Have the function transpose the 4 × 5 matrix and store the results 
//    in the 5 × 4 matrix. Also write a main() routine to test the function.
//
// b. Using variable-length arrays, rewrite the transposeMatrix() function developed 
//    in exercise 12a to take the number of rows and columns as arguments, and to transpose 
//    the matrix of the specified dimensions.

#include <stdio.h>

void display_matrix(int* n[], int rows, int columns)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			printf("%2i ", n[i][j]);
		}

		printf("\n");
	}
}

void transposeMatrix(int* n[], int* m[])
{
	n[0][0] = 0;
	m[0][0] = 0;
}

void test_runner(int* n[], int* m[])
{
	display_matrix(n, 4, 5);
	display_matrix(m, 5, 4);
}

int main(void)
{
	int n[4][5] = {
		{ 1, 2, 3, 4, 5 },
		{ 1, 2, 3, 4, 5 },
		{ 1, 2, 3, 4, 5 },
		{ 1, 2, 3, 4, 5 },
	};

	int m[5][4] = { 0 };

	test_runner(n, m);

	return 0;
}