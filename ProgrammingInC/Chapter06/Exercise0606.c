// Exercise 6.6
//
// You don’t need to use an array to generate Fibonacci numbers. You can simply use 
// three variables: two to store the previous two Fibonacci numbers and one to store 
// the current one. Rewrite Program 6.3 so that arrays are not used. Because you’re 
// no longer using an array, you need to display each Fibonacci number as you generate it.
// 
// Kochan, Stephen G. Programming in C, Fourth Edition

// Program 6.3 for reference
// int main(void)
// {
// 	int Fibonacci[15], i;
// 
// 	Fibonacci[0] = 0;
// 	Fibonacci[1] = 1;
// 
// 	for (i = 2; i < 15; ++i)
// 		Fibonacci[i] = Fibonacci[i - 2] + Fibonacci[i - 1];
// 
// 	for (i = 0; i < 15; ++i)
// 		printf("%i\n", Fibonacci[i]);
// 
// 	return 0;
// }

#include <stdio.h>

int main(void)
{
	int Fibonacci_1 = 0;
	int Fibonacci_2 = 1;
	int Fibonacci_3;

	printf("%i\n", Fibonacci_1);
	printf("%i\n", Fibonacci_2);

	for (int i = 2; i < 15; ++i)
	{
		Fibonacci_3 = Fibonacci_1 + Fibonacci_2;
		printf("%i\n", Fibonacci_3);
		Fibonacci_1 = Fibonacci_2;
		Fibonacci_2 = Fibonacci_3;
	}

	return 0;
}