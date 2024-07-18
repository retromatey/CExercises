#include <stdio.h>
#include <stdarg.h>

enum drink {
	MUDSLIDE,
	FUZZY_NAVEL,
	MONKEY_GLAND,
	ZOMBIE
};

double price(enum drink d)
{
	switch (d)
	{
	case MUDSLIDE:
		return 6.79;
	case FUZZY_NAVEL:
		return 5.31;
	case MONKEY_GLAND:
		return 4.82;
	case ZOMBIE:
		return 5.89;
	}

	return 0;
}

double total(int args, ...)
{
	double result = 0;

	va_list ap;
	va_start(ap, args);
	for (int i = 0; i < args; i++)
	{
		enum drink d = va_arg(ap, enum drink);
		result += price(d);
	}
	va_end(ap);

	return result;
}

int main(int argc, char* argv[])
{
	printf("The price is %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
	printf("The price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
	printf("The price is %.2f\n", total(1, ZOMBIE));
	return 0;
}