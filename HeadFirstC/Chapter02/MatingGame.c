#include <stdio.h>

int main() 
{
	int contestants[] = {1, 2, 3};
	int *choice = contestants;
	contestants[0] = 2;					// 0 -> 2
	contestants[1] = contestants[2];	// 1 -> contenstants[2] -> 3
	contestants[2] = *choice;			// 2 -> *choice -> contestants[0] -> 2
	printf("I'm going to pick contestant number %i\n", contestants[2]);

	return 0;
}