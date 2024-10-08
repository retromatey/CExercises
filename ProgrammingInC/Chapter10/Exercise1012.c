// Exercise 10.12
// 
// Given the following declarations below on lines 13 - 16, 
// determine whether each printf() call from the following sets is valid and produces 
// the same output as other calls from the set.
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>

int main(void)
{
	char* message = "Programming in C is fun\n";
	char  message2[] = "You said it\n";
	char* format = "x = %i\n";
	int   x = 100;

	/*** set 1 ***/
	printf("Programming in C is fun\n");
	printf("%s", "Programming in C is fun\n");
	printf("%s", message);
	printf(message);

	/*** set 2 ***/
	printf("You said it\n");
	printf("%s", message2);
	printf(message2);
	printf("%s", &message2[0]);

	/*** set 3 ***/
	printf("said it\n");
	printf(message2 + 4);
	printf("%s", message2 + 4);
	printf("%s", &message2[4]);

	/*** set 4 ***/
	printf("x = %i\n", x);
	printf(format, x);

	return 0;
}