/*
 * Program to evaluate face values.
 * Released under the Vegas Public License.
 * (c)2014 The College Blackjack Team.
 */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char card_name[3];
	int count = 0;

	do
	{
		puts("Enter the card_name:");
		scanf("%2s", card_name);
		int val = 0;

		switch (card_name[0])
		{
			case 'K':
			case 'Q':
			case 'J':
				val = 10;
				break;
			case 'A':
				val = 11;
				break;
			case 'X':
				continue;
			default:
				val = atoi(card_name);
				if (val < 1 || val > 10)
				{
					puts("Please enter a proper value\n");
					continue;
				}
		}

		if (val > 2 && val < 7)	// Check if the value is 3 to 6
		{
			count++;
		}
		else if (val == 10)		// Otherwise check if the card was 10, J, Q, or K
		{
			count--;
		}

		printf("Current count: %i\n", count);

	} while (card_name[0] != 'X');

	return 0;
}