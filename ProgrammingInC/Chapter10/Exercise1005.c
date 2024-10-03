// Exercise 10.5
// 
// A doubly linked list is a list in which each entry contains a pointer to the 
// preceding entry in the list as well as a pointer to the next entry in the list. 
// Define the appropriate structure definition for a doubly linked list entry and 
// then write a small program that implements a small doubly linked list and prints 
// out the elements of the list.
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>

struct entry 
{
	int value;
	struct entry* next;
	struct entry* prev;
};

struct entry* head;

void print_entries(struct entry* ptr)
{
	while (ptr != NULL)
	{
		printf("%i\n", ptr->value);
		ptr = ptr->next;
	}
}

int main(void)
{
	struct entry n100;
	struct entry n200;
	struct entry n300;

	n100.value = 100;
	n100.prev = NULL;
	n100.next = &n200;

	n200.value = 200;
	n200.prev = &n100;
	n200.next = &n300;

	n300.value = 300;
	n300.prev = &n200;
	n300.next = NULL;

	head = &n100;

	printf("\n**********************************************\n");
	printf("\nInitial list\n\n");
	print_entries(&n100);
	printf("\n**********************************************\n");

	return 0;
}