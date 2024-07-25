// Program 6.8 - Generating Fibonacci Numbers Using Variable Length Arrays

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, numFibs;

	printf("How many Fibonacci numbers do you want (between 1 and 75)? ");

	if (scanf("%i", &numFibs) == 1)
	{
		if (numFibs < 1 || numFibs > 75)
		{
			printf("Bad number, sorry!\n");
			return 1;
		}

		unsigned long long int* Fibonacci = (unsigned long long int*)malloc(numFibs * sizeof(unsigned long long int));

		if (Fibonacci != NULL)
		{
			Fibonacci[0] = 0;

			if (numFibs > 1)
			{
				Fibonacci[1] = 1;

				for (i = 2; i < numFibs; ++i)
					Fibonacci[i] = Fibonacci[i - 2] + Fibonacci[i - 1];
			}

			for (i = 0; i < numFibs; ++i)
				printf("%llu  ", Fibonacci[i]);

			printf("\n");

			free(Fibonacci);
		}
	}

	return 0;
}