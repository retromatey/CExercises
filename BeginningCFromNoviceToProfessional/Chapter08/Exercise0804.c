// Define a function that will return the number of words in a string that is passed as an argument. 
// (Words are separated by spaces or punctuation characters. Assume the string doesn't contain 
// embedded single or double quotes - that is, no words such as "isn't.") Define a second function 
// that will segment a string that's passed as the first argument to the function into words, and 
// return the words stored in the array that's passed as the second argument. Define a third function 
// that will return the number of letters in a string that's passed as the argument. Use these 
// functions to implement a program that will read a string containing text from the keyboard and 
// then output all the words from the text ordered from the shortest to the longest.
// Exercise0804.c

// Ivor Horton. Beginning C : From Novice to Professional, Fourth Edition (p. 328). Kindle Edition.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WORD_LIMIT 200

int num_words(char* string);
void segment(char* string, char* buffer[]);
int num_letters(char* string);
void order_words(char* words[]);

int main(int argc, char* argv[])
{
	int word_count;
	const char* test_string = "Let us order this sentence into word sizes together.";

	word_count = num_words(test_string);
	char* words[WORD_LIMIT] = { 0 };
	segment(test_string, words);
	order_words(words);

	return 0;
}

int num_words(char* string)
{
	int count = 0;

	if (string != NULL)
	{
		int len = strlen(string);
		int letters_read = 0;

		for (int i = 0; i < len; i++)
		{
			if (isalpha(string[i]))
			{
				letters_read++;
			}
			else if (letters_read > 0)
			{
				if (string[i] == ' ' || string[i] == ',' || string[i] == '.' || string[i] == '?' || string[i] == '!' || string[i] == ';')
				{
					count++;
					letters_read = 0;
				}
			}
		}
	}

	return count;
}

void segment(char* string, char* words[])
{
	if (string != NULL)
	{
		char buffer[256] = { 0 };
		int len = strlen(string);
		int letters_read = 0;
		int count = 0;

		for (int i = 0; i < len; i++)
		{
			if (isalpha(string[i]))
			{
				buffer[letters_read] = string[i];
				letters_read++;
			}
			else if (letters_read > 0)
			{
				if (string[i] == ' ' || string[i] == ',' || string[i] == '.' || string[i] == '?' || string[i] == '!' || string[i] == ';')
				{
					buffer[letters_read] = '\0';
					words[count] = (char*)(malloc(sizeof(char) * (letters_read+1)));
					strcpy(words[count], buffer);
					count++;
					letters_read = 0;
				}
			}
		}
	}
}

int num_letters(char* string)
{
	if (string != NULL)
		return strlen(string);

	return 0;
}

void order_words(char* words[])
{
	char temp[256] = { 0 };
	int largest_index = 0;
	for (int i = 0; i < WORD_LIMIT-1; i++)
	{
		largest_index = i;

		if (words[i] != NULL)
		{
			for (int j = i + 1; j < WORD_LIMIT; j++)
			{
				if (num_letters(words[largest_index]) < num_letters(words[j]))
				{
					largest_index = j;
				}
			}

			strcpy(temp, words[largest_index]);
			strcpy(words[largest_index], words[i]);
			strcpy(words[i], temp);
		}
		else
		{
			break;
		}
	}
}
