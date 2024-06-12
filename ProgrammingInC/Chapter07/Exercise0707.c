// Prime numbers can also be generated by an algorithm known as the Sieve of Erastosthenes.
// The algorithm for this procedure is presented here. Write a program that implements this 
// algorithm. Have the program find all prime numbers up to n = 150.

// Sieve of Erastosthenes Algorithm To Display All Prime Numbers Between 1 and n:
// Step 1: Define an array of integers p. Set all elements p[i] to 0, 2 <= i <= n.
// Step 2: Set i to 2. 
// Step 3: If i > n, the algorithm terminates.
// Step 4: If p[i] is 0, then i is prime.
// Step 5: For all positive integer values of j, such that i * j <= n, set p[i*j] to 1. 
// Step 6: Add 1 to i and go to step 3.

// Kochan, Stephen G. Programming in C (p. 209). Pearson Education. Kindle Edition.

#include <stdio.h>

int main() 
{
	int n = 150;
	int p[151];
	int i;
	int j;

	p[0] = 0;
	p[1] = 1;

	for (i = 2; i <= n; i++)
		p[i] = 0;

	i = 2;
	while (i <= n)
	{
		if (p[i] == 0)
			printf("%d\n", i);

		for (j = 1; j * i <= n; j++)
			p[j * i] = 1;

		i += 1;
	}

	return 0;
}