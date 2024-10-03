// Exercise 10.4
// 
// Write a function called removeEntry() to remove an entry from a linked list. The sole 
// argument to the procedure should be a pointer to the list. Have the function remove 
// the entry after the one pointed to by the argument. (Why can’t you remove the entry 
// pointed to by the argument?) You need to use the special structure you set up in 
// exercise 3 to handle the special case of removing the first element from the list.
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

void removeEntry(struct entry* prevEntry)
{
	if (prevEntry == NULL)
	{
		head = head->next;
	}
	else
	{
		prevEntry->next = prevEntry->next->next;
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

	printf("\n**********************************************\n");
	printf("Initial list\n");
	print_entries(&n100);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	struct entry n201;
	n201.value = 201;
	n201.next = NULL;
	insertEntry(&n201, &n200);
	printf("\nAfter inserting 201\n");
	print_entries(head);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	struct entry n99;
	n99.value = 99;
	n99.next = NULL;
	insertEntry(&n99, NULL);
	printf("\nAfter insertion 99\n");
	print_entries(head);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	struct entry n98;
	n98.value = 98;
	n98.next = NULL;
	insertEntry(&n98, NULL);
	printf("\nAfter insertion 98\n");
	print_entries(head);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	removeEntry(head);
	printf("\nAfter removing 99\n");
	print_entries(head);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	removeEntry(NULL);
	printf("\nAfter removing 98\n");
	print_entries(head);
	printf("\n**********************************************\n");

	return 0;
}