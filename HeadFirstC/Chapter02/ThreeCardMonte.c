#include <stdio.h>

int main() 
{
	//char* cards = "JQK";			// This is a string literal, this variable can't be modified
	//const char* cards = "JQK";	// Using the const keyword is a good practice
	char cards[] = "JQK";			// This is an array, this variable can be modified
	char a_card = cards[2];

	cards[2] = cards[1]; // 2 -> Q
	cards[1] = cards[0]; // 1 -> J
	cards[0] = cards[2]; // 0 -> Q
	cards[2] = cards[1]; // 2 -> J
	cards[1] = a_card;   // 1 -> K

	puts(cards);	// QKJ

	return 0;
}