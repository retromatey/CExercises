// Program 7.16 - Illustrating Static and Automatic Variables

#include <stdio.h>

void auto_static(void)
{
	int autoVar = 1;
	static int staticVar = 1;

	printf("automatic = %i, static = %i\n", autoVar, staticVar);

	++autoVar;
	++staticVar;
}

int main(void)
{
	int i;

	for (i = 0; i < 5; ++i)
		auto_static();

	return 0;
}