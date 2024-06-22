// Write a function called removeString to remove a specified number of characters 
// from a character string. The function should take three arguments: the source 
// string, the starting index number in the source string, and the number of 
// characters to remove. So, if the character array text contains the string 
// "the wrong son", the call 
// 
// removeString(text, 4, 6); 
// 
// has the effect of removing the characters “wrong” (the word “wrong” plus the 
// space that follows) from the array text. The resulting string inside text is 
// then "the son".

// Kochan, Stephen G. Programming in C (p. 381). Pearson Education. Kindle Edition.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Removes a specified number of characters from a character string.
 *
 * This function takes a source string and removes a specified number of characters
 * starting from a given index. If the number of characters to remove extends beyond
 * the length of the string, the string is terminated at the starting index. Otherwise,
 * the characters following the removed section are shifted left to fill the gap, and
 * the string is properly null-terminated.
 *
 * @param text The source string from which characters are to be removed.
 * @param start The starting index in the source string from where characters are to be removed.
 * @param count The number of characters to remove from the source string.
 *
 * Note: The function does nothing if `text` is NULL, `start` is out of bounds,
 * or `count` is non-positive.
 */
void removeString(char* text, int start, int count)
{
    if (text != NULL)
    {
        int len = strlen(text);

        if (start >= 0 && count > 0 && start < len)
        {
            if (start + count >= len) 
            {
                text[start] = '\0';  // If count exceeds the remaining characters, just terminate at start
            }
            else 
            {
                for (int i = start; i < len - count; ++i)
                    text[i] = text[i + count];
                
                text[len - count] = '\0';
            }
        }
    }
}

int main()
{
	char text[200] = { 0 };
	char result[200] = { 0 };
	char expected[200] = { 0 };
	int start;
	int count;

	// Test 1 - Original test from problem text.
	strcpy(text, "the wrong son");
	strcpy(result, "the wrong son");
	strcpy(expected, "the son");
	start = 4;
	count = 6;
	removeString(result, start, count);
	printf("Test 1 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");
    
    // Test 2 - Removing " world" from "hello world".
    strcpy(text, "hello world");
    strcpy(result, "hello world");
    strcpy(expected, "hello");
    start = 5;
    count = 6;
    removeString(result, start, count);
    printf("Test 2 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");

    // Test 3 - Removing "def" from "abcdef".
    strcpy(text, "abcdef");
    strcpy(result, "abcdef");
    strcpy(expected, "abc");
    start = 3;
    count = 3;
    removeString(result, start, count);
    printf("Test 3 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");

    // Test 4 - Removing 0 characters from "abcdef".
    strcpy(text, "abcdef");
    strcpy(result, "abcdef");
    strcpy(expected, "abcdef");
    start = 3;
    count = 0;
    removeString(result, start, count);
    printf("Test 4 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");

    // Test 5 - Removing "abc" from the beginning of "abcdef".
    strcpy(text, "abcdef");
    strcpy(result, "abcdef");
    strcpy(expected, "def");
    start = 0;
    count = 3;
    removeString(result, start, count);
    printf("Test 5 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");

    // Test 6 - Removing the entire string "abcdef".
    strcpy(text, "abcdef");
    strcpy(result, "abcdef");
    strcpy(expected, "");
    start = 0;
    count = 6;
    removeString(result, start, count);
    printf("Test 6 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");

    // Test 7 - Removing "cd" from "abcdef".
    strcpy(text, "abcdef");
    strcpy(result, "abcdef");
    strcpy(expected, "abef");
    start = 2;
    count = 2;
    removeString(result, start, count);
    printf("Test 7 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");

    // Test 8 - Trying to remove characters starting at an index beyond the string length.
    strcpy(text, "abcdef");
    strcpy(result, "abcdef");
    strcpy(expected, "abcdef");
    start = 10;
    count = 2;
    removeString(result, start, count);
    printf("Test 8 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");

    // Test 9 - Using a negative count.
    strcpy(text, "abcdef");
    strcpy(result, "abcdef");
    strcpy(expected, "abcdef");
    start = 2;
    count = -1;
    removeString(result, start, count);
    printf("Test 9 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");

    // Test 10 - Using a negative starting index.
    strcpy(text, "abcdef");
    strcpy(result, "abcdef");
    strcpy(expected, "abcdef");
    start = -1;
    count = 2;
    removeString(result, start, count);
    printf("Test 10 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");

    // Test 11 - start + count exceeds string length.
    strcpy(text, "abcdef");
    strcpy(result, "abcdef");
    strcpy(expected, "abc");
    start = 3;
    count = 4;
    removeString(result, start, count);
    printf("Test 11 - text: [%s], result: [%s], expected: [%s], %s\n", text, result, expected, strcmp(result, expected) == 0 ? "PASS" : "FAIL");

	return 0;
}