// Exercise 10.3
// 
// The function developed in exercise 2 only inserts an element after an existing element in 
// the list, thereby preventing you from inserting a new entry at the front of the list. How 
// can you use this same function and yet overcome this problem? (Hint: Think about setting 
// up a special structure to point to the beginning of the list.)
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>

struct entry 
{
	int value;
	struct entry* next;
};

struct entry* head;

void insertEntry(struct entry* newEntry, struct entry* prevEntry)
{
	if (prevEntry == NULL)
	{
		newEntry->next = head;
		head = newEntry;
	}
	else
	{
		newEntry->next = prevEntry->next;
		prevEntry->next = newEntry;
	}
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
	struct entry n100;
	struct entry n200;
	struct entry n300;

	n100.value = 100;
	n100.next = &n200;

	n200.value = 200;
	n200.next = &n300;

	n300.value = 300;
	n300.next = NULL;

	head = &n100;

	printf("Before insertion\n");
	print_entries(&n100);

	struct entry n201;
	n201.value = 201;
	n201.next = NULL;
	insertEntry(&n201, &n200);

	printf("\nAfter insertion 1\n");
	print_entries(head);

	struct entry n99;
	n99.value = 99;
	n99.next = NULL;
	insertEntry(&n99, NULL);

	printf("\nAfter insertion 2\n");
	print_entries(head);

	struct entry n98;
	n98.value = 98;
	n98.next = NULL;
	insertEntry(&n98, NULL);

	printf("\nAfter insertion 3\n");
	print_entries(head);

	return 0;
}