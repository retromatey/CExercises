// Exercise 6.4
//
// Write a program that calculates the average of an array of 10 floating-point values.
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>

#define ARRAY_SIZE 10

int main(void)
{
	float total = 0.0;
	float avg;
	float values[ARRAY_SIZE] =
	{
		1.0,
		2.0,
		3.0,
		4.0,
		5.0,
		6.0,
		7.0,
		8.0,
		9.0,
		10.0,
	};


	for (int i = 0; i < ARRAY_SIZE; i++)
		total += values[i];

	avg = total / ARRAY_SIZE;

	printf("The average is %.2f\n", avg);

	return 0;
}