// Exercise 10.6
// 
// Develop insertEntry() and removeEntry() functions for a doubly linked list that 
// are similar in function to those developed in previous exercises for a singly 
// linked list. Why can your removeEntry() function now take as its argument a direct 
// pointer to the entry to be removed from the list?
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

/**
 * @brief Inserts an entry into a doubly linked list.
 *
 * This function inserts the specified entry into the doubly linked list.
 * If the previous entry is NULL, the new entry is inserted at the head of the list.
 * Otherwise, the new entry is inserted after the specified previous entry.
 * The function updates the previous and next pointers of the neighboring entries
 * to include the new entry.
 *
 * @param nextEntry A pointer to the entry to be inserted into the list.
 * @param prevEntry A pointer to the entry after which the new entry should be inserted.
 *                  If NULL, the new entry is inserted at the head of the list.
 */
void insertEntry(struct entry* nextEntry, struct entry* prevEntry)
{
	if (prevEntry == NULL)
	{
		nextEntry->prev = NULL;
		nextEntry->next = head;
		head->prev = nextEntry;
		head = nextEntry;
	}
	else
	{
		nextEntry->prev = prevEntry;
		nextEntry->next = prevEntry->next;
		prevEntry->next = nextEntry;
	}
}

/**
 * @brief Removes an entry from a doubly linked list.
 *
 * This function removes the specified entry from the doubly linked list.
 * It updates the previous and next pointers of the neighboring entries
 * to bypass the entry being removed. If the entry to be removed is the
 * head of the list, the head pointer is updated accordingly.
 *
 * @param ptr A pointer to the entry to be removed from the list.
 */
void removeEntry(struct entry* ptr)
{
	struct entry* prev = ptr->prev;
	struct entry* next = ptr->next;

	if (prev != NULL)
		prev->next = next;

	if (next != NULL)
		next->prev = prev;

	if (prev == NULL)
		head = next;

	ptr->prev = NULL;
	ptr->next = NULL;
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

	printf("\n**********************************************\n");
	struct entry n201;
	n201.value = 201;
	n201.next = NULL;
	n201.prev = NULL;
	insertEntry(&n201, &n200);
	printf("\nAfter inserting 201\n");
	print_entries(head);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	struct entry n301;
	n301.value = 301;
	n301.next = NULL;
	n301.prev = NULL;
	insertEntry(&n301, &n300);
	printf("\nAfter inserting 301\n");
	print_entries(head);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	struct entry n99;
	n99.value = 99;
	n99.prev = NULL;
	n99.next = NULL;
	insertEntry(&n99, NULL);
	printf("\nAfter inserting 99\n");
	print_entries(head);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	struct entry n98;
	n98.value = 98;
	n98.prev = NULL;
	n98.next = NULL;
	insertEntry(&n98, NULL);
	printf("\nAfter inserting 98\n");
	print_entries(head);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	removeEntry(&n301);
	printf("\nAfter removing 301\n");
	print_entries(head);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	removeEntry(&n99);
	printf("\nAfter removing 99\n");
	print_entries(head);
	printf("\n**********************************************\n");

	printf("\n**********************************************\n");
	removeEntry(&n98);
	printf("\nAfter removing 98\n");
	print_entries(head);
	printf("\n**********************************************\n");

	return 0;
}