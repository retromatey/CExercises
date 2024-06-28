// Write a program to use a struct to count the number of occurrences of each different 
// word in a paragraph of text that's entered from the keyboard.

// Ivor Horton. Beginning C : From Novice to Professional, Fourth Edition (p. 466). Kindle Edition.

// Exercise1104.c 
// TODO:
//  - lower case word for better comparison
//  - handle punctuation
//  - find a better way to determine end of word_info array

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 500

typedef struct word_info_ {
	char* word;
	int count;
} word_info;

void count_words(word_info* words);
void display_words(word_info* words);

int main(int argc, char* argv[])
{
	word_info words[MAX_WORDS] = { 0 };
	count_words(words);
	display_words(words);

	return 0;
}

int word_position(word_info* words, char* word)
{
	int position = -1;

	for (int i = 0; i < MAX_WORDS; i++)
	{
		if (words[i].count == 0)
			break;

		int test = strcmp(word, words[i].word);
		if (strcmp(word, words[i].word) == 0)
		{
			position = i;
			break;
		}
	}

	return position;
}

void count_words(word_info* words)
{
	char buffer[256] = { 0 };

	while (fscanf(stdin, " %255s", buffer) == 1)
	{
		if (buffer == EOF)
			break;

		int position = word_position(words, buffer);

		if (position >= 0)
		{
			words[position].count++;
		}
		else
		{
			int end = 0;
			for (int i = 0; i < MAX_WORDS; i++)
			{
				if (words[i].count == 0)
				{
					end = i;
					break;
				}
			}
			words[end].count = 1;
			words[end].word = (char*)malloc(sizeof(char) * strlen(buffer)+1);
			strcpy(words[end].word, buffer);
		}
	}
}

void display_words(word_info* words)
{
	for (int i = 0; i < MAX_WORDS; i++)
	{
		if (words[i].count == 0)
			break;

		fprintf(stdout, "Word: [%s], Count: [%d]\n", words[i].word, words[i].count);
	}
}
