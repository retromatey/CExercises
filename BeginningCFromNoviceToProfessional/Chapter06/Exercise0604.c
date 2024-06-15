// A palindrome is a phrase that reads the same backward as forward, ignoring whitespace and 
// punctuation. For example, "Madam, I'm Adam" and "Are we not drawn onward, we few? Drawn 
// onward to new era?" are palindromes. Write a program that will determine mine whether a 
// string entered from the keyboard is a palindrome.

// Ivor Horton. Beginning C: From Novice to Professional, Fourth Edition (p. 240). Kindle Edition.

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_INPUT 200

bool set_input(char* input, size_t input_size) 
{
	if (fgets(input, input_size, stdin) == NULL)
		return false;

	// Remove '\n' added by fgets
	size_t input_len = strlen(input);
	if (input_len > 0 && input[input_len - 1] == '\n')
		input[input_len - 1] = '\0';

	return true;
}

// Convert to uppercase and filter non-alphabetic characters
void sanitize_input(const char* input, char* sanitized)
{
	size_t input_len = strlen(input);
	int sanitized_index = 0;

	for (size_t i = 0; i < input_len; i++)
		if (isalpha(input[i]))
			sanitized[sanitized_index++] = toupper(input[i]);

	sanitized[sanitized_index] = '\0';
}

bool is_palindrome(const char* sanitized) 
{
	size_t len = strlen(sanitized);
	for (size_t i = 0; i < len / 2; i++)
		if (sanitized[i] != sanitized[len - 1 - i])
			return false;

	return true;
}

int main()
{
	char input[MAX_INPUT];
	printf("Enter a string:\n");

	if (set_input(input, sizeof(input)))
	{
		char sanitized[MAX_INPUT];
		sanitize_input(input, sanitized);
		bool match = is_palindrome(sanitized);
		printf("[%s] %s a palindrome\n", input, match ? "is" : "is not");
	}
	else
	{
		printf("Error reading input.\n");
		exit(1);
	}

	return 0;
}