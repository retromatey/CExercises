#include <stdio.h>
#include <stdarg.h>

void print_ints(int args, ...)
{
	va_list ap;
	va_start(ap, args);
	int i;
	for (i = 0; i < args; i++)
		printf("argument: %i\n", va_arg(ap, int));
	va_end(ap);
}

int main(int argc, char *argv[])
{
	print_ints(4, 1, 2, 3, 4);
	return 0;
}