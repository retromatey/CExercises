#include <stdio.h>

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
	default:
		break;
	}
}

int main(int argc, char *argv[])
{
	return 0;
}