// Exercise: 7.2
// Modify Program 7.4 so the value of triangularNumber is returned by the function. 
// Then go back to Program 4.5 and change that program so that it calls the new 
// version of the calculateTriangularNumber() function.

#include <stdio.h>

int calculateTriangularNumber(int n)
{
	int i, triangularNumber = 0;

	for (i = 1; i <= n; ++i)
		triangularNumber += i;

	return triangularNumber;
}

int main(void)
{
    int number, triangularNumber, counter;

    for (counter = 1; counter <= 5; ++counter) 
    {
        printf("What triangular number do you want? ");

        if (scanf("%i", &number) == 1)
        {
            triangularNumber = calculateTriangularNumber(number);
            printf("Triangular number %i is %i\n\n", number, triangularNumber);
        }
		else
		{
            printf("Invalid input. Please enter an integer.\n");
            while (getchar() != '\n');
		}

    }

    return 0;
}


// Sample output:
// 
// What triangular number do you want ? 12
// Triangular number 12 is 78
// 
// What triangular number do you want ? 25
// Triangular number 25 is 325
// 
// What triangular number do you want ? 50
// Triangular number 50 is 1275
// 
// What triangular number do you want ? 75
// Triangular number 75 is 2850
// 
// What triangular number do you want ? 83
// Triangular number 83 is 3486