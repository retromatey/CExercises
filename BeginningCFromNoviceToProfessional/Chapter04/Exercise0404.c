// Use nested loops to output a box bounded by asterisks as in Program 4.2, but with a width 
// and height that's entered by the user. For example, a box ten characters wide and seven 
// characters high would display as follows:

//   1234567890
// 1 **********
// 2 *        *
// 3 *        *
// 4 *        *
// 5 *        *
// 6 *        *
// 7 **********

// Ivor Horton.Beginning C : From Novice to Professional, Fourth Edition(p. 174).Kindle Edition.


#include <stdio.h>

int main() 
{
	int width;
	int height;

	printf("Enter a width: ");
	scanf_s("%d", &width);

	printf("Enter a height: ");
	scanf_s("%d", &height);

	for (int i = 1; i <= height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (i == 1 || i == height)
				printf("*");
			else if (j == 1 || j == width)
				printf("*");
			else
				printf(" ");
		}

		printf("\n");
	}

	return 0;
}