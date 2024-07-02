// Write a program that will read an arbitrary number of proverbs from the keyboard and store 
// them in memory that's allocated at runtime. The program should then output the proverbs 
// ordered by their length, starting with the shortest and ending with the longest.

// Ivor Horton. Beginning C : From Novice to Professional, Fourth Edition (p. 294). Kindle Edition.

// Exercise0702.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PROVERBS 100
#define MAX_INPUT 256

void sort(char* proverbs[])
{
	char temp[MAX_INPUT] = { 0 };
	int largest = 0;

	for (int i = 0; i < MAX_PROVERBS + 1 && proverbs[i] != NULL; i++)
	{
		largest = i;

		for (int j = i + 1; j < MAX_PROVERBS && proverbs[j] != NULL; j++)
		{
			if (strlen(proverbs[i]) < strlen(proverbs[j]))
			{
				largest = j;
			}
		}

		strcpy(temp, proverbs[i]);
		strcpy(proverbs[i], proverbs[largest]);
		strcpy(proverbs[largest], temp);
	}
}

int main(int argc, char *argv[])
{
	char* proverbs[MAX_PROVERBS];
	memset(proverbs, 0, sizeof(proverbs));

	char input_buffer[MAX_INPUT] = { 0 };
	int entry_num = 0;

	while (strcmp(input_buffer, "end") != 0)
	{
		fgets(input_buffer, MAX_INPUT, stdin);
		int len = strlen(input_buffer);
		input_buffer[len - 1] = '\0';

		if (strcmp(input_buffer, "end") == 0)
			break;

		proverbs[entry_num] = strdup(input_buffer);		// disable the warning for strdup - _CRT_NONSTDC_NO_WARNINGS
		entry_num++;
	}

	sort(proverbs);

	for (int i = 0; i < entry_num; i++)
		free(proverbs[i]);

	return 0;
}