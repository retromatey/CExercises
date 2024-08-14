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

void transposeMatrix(int* n[], int* m[], int n_rows, int n_columns)
{
	for (int i = 0; i < n_rows; i++)
	{
		for (int j = 0; j < n_columns; j++)
		{
			m[j][i] = n[i][j];
		}
	}
}

void test_runner(int* n[], int* m[], int n_rows, int n_columns)
{
	transposeMatrix(n, m, n_rows, n_columns);
	display_matrix(n, n_rows, n_columns);
	display_matrix(m, n_columns, n_rows);
}

int main(void)
{
	int n_rows = 4;
	int n_columns = 5;

	int* n[4];
	n[0] = (int[5]){ 1,  2,  3,  4,  5 };
	n[1] = (int[5]){ 6,  7,  8,  9, 10 };
	n[2] = (int[5]){ 11, 12, 13, 14, 15 };
	n[3] = (int[5]){ 16, 17, 18, 19, 20 };

	int* m[5];
	m[0] = (int[4]){ 0 };
	m[1] = (int[4]){ 0 };
	m[2] = (int[4]){ 0 };
	m[3] = (int[4]){ 0 };
	m[4] = (int[4]){ 0 };

	test_runner(n, m, n_rows, n_columns);

	return 0;
}