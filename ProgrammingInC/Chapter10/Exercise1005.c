// Write a function called findString to determine if one character string exists inside another string. 
// The first argument to the function should be the character string that is to be searched and the 
// second argument is the string you are interested in finding. If the function finds the specified 
// string, have it return the location in the source string where the string was found. If the function 
// does not find the string, have it return –1. So, for example, the call 
// 
//     index = findString ("a chatterbox", "hat"); 
// 
// searches the string "a chatterbox" for the string "hat". Because "hat" does exist inside the source 
// string, the function returns 3 to indicate the starting position inside the source string where "hat" 
// was found.

// Kochan, Stephen G. Programming in C (pp. 380 - 381). Pearson Education. Kindle Edition.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Searches for a substring within a source string and returns its position.
 *
 * This function iterates through the source string to find the first occurrence of the
 * specified search string. If the search string is found, the function returns the index
 * of the first character of the first occurrence of the search string within the source string.
 * If the search string is not found, the function returns -1.
 *
 * The search is case-sensitive and considers the exact sequence of characters in the search string.
 *
 * @param source The source string to be searched.
 * @param search The string to search for within the source string.
 * @return The starting index of the first occurrence of the search string within the source string;
 *         -1 if the search string is not found.
 */
int findString(char* source, char* search)
{
	if (source != NULL && search != NULL)
	{
		size_t source_len = strlen(source);
		size_t search_len = strlen(search);

		if (source_len > 0 && search_len > 0 && search_len <= source_len)
		{
			size_t stop = source_len - search_len;
			for (size_t i = 0; i <= stop; i++)
				if (strncmp(&source[i], search, search_len) == 0)
					return i;

			// First attempt.  This logic might skip valid starting points for a match because of the reset of match_count to zero.
			// source = "ababcabc"
			// search = "abc"
			// position should be 2, but this logic will emit 5
			//int match_count = 0;
			//for (size_t i = 0; i < source_len; i++)
			//{
			//	if (source[i] == search[match_count])
			//		match_count++;
			//	else
			//		match_count = 0;
			//
			//	if (match_count == search_len)
			//		return i - search_len + 1;
			//}
		}
	}

	return -1;
}

int main()
{
	char source[200];
	char search[200];
	int expected;

	// Test 1
	strcpy(source, "a chatterbox");
	strcpy(search, "hat");
	expected = 3;
	printf("Source: [%s], Search: [%s], Result: [%d], Expected: [%d]\n", source, search, findString(source, search), expected);

	// Test 2
	strcpy(source, "hello world");
	strcpy(search, "world");
	expected = 6;
	printf("Source: [%s], Search: [%s], Result: [%d], Expected: [%d]\n", source, search, findString(source, search), expected);

	// Test 3
	strcpy(source, "abcabcabc");
	strcpy(search, "cab");
	expected = 2;
	printf("Source: [%s], Search: [%s], Result: [%d], Expected: [%d]\n", source, search, findString(source, search), expected);

	// Test 4
	strcpy(source, "a chatterbox");
	strcpy(search, "box");
	expected = 9;
	printf("Source: [%s], Search: [%s], Result: [%d], Expected: [%d]\n", source, search, findString(source, search), expected);

	// Test 5
	strcpy(source, "a chatterbox");
	strcpy(search, "hello");
	expected = -1;
	printf("Source: [%s], Search: [%s], Result: [%d], Expected: [%d]\n", source, search, findString(source, search), expected);

	// Test 5
	strcpy(source, "ababcabc");
	strcpy(search, "abc");
	expected = 2;
	printf("Source: [%s], Search: [%s], Result: [%d], Expected: [%d]\n", source, search, findString(source, search), expected);

	return 0;
}