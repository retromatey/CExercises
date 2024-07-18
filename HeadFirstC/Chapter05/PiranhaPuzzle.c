#include <stdio.h>

struct fish {
	const char* name;
	const char* species;
	int teeth;
	int age;
};

void catalog(struct fish f);

int main(int argc, char* argv[])
{
	struct fish snappy = { "Snappy", "Piranha", 69, 4 };
	catalog(snappy);

	return 0;
}

void catalog(struct fish f)
{
	printf("%s is a %s with %i teeth. He is %i\n",
		f.name, f.species, f.teeth, f.age);
}
