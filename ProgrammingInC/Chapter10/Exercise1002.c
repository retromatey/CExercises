// Exercise 10.2
// 
// Write a function called insertEntry() to insert a new entry into a linked list. 
// Have the procedure take as arguments a pointer to the list entry to be inserted 
// (of type struct entry as defined in this chapter), and a pointer to an element 
// in the list after which the new entry is to be inserted.
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>

struct entry 
{
	int value;
	struct entry* next;
};

void insertEntry(struct entry* newEntry, struct entry* prevEntry)
{
	newEntry->next = prevEntry->next;
	prevEntry->next = newEntry;
}

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
	struct entry n1;
	struct entry n2;
	struct entry n3;

	n1.value = 100;
	n1.next = &n2;

	n2.value = 200;
	n2.next = &n3;

	n3.value = 300;
	n3.next = NULL;

	printf("Before insertion\n");
	print_entries(&n1);

	struct entry n2a;
	n2a.value = 201;
	n2a.next = NULL;
	insertEntry(&n2a, &n2);

	printf("\nAfter insertion\n");
	print_entries(&n1);

	return 0;
}