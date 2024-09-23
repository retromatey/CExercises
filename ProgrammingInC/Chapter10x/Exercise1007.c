// Write a function called insertString to insert one character string into another 
// string. The arguments to the function should consist of the source string, the 
// string to be inserted, and the position in the source string where the string is 
// to be inserted. So, the call
//
//     insertString("the wrong son", "per", 10); 
// 
// results in the character string "per" being inserted inside "the wrong son", 
// beginning at text[10]. Therefore, the character string "the wrong person" is stored 
// inside the source array after the function returned.

// Kochan, Stephen G. Programming in C (p. 381). Pearson Education. Kindle Edition.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Inserts a string into another string at a specified position.
 *
 * This function takes a source string and inserts another string (insert) into it at the specified position.
 * The source string must have enough space to accommodate the inserted string, including the null terminator.
 * The function first shifts the part of the source string that comes after the insertion point to the right,
 * making space for the new string. Then, it copies the insert string into the source string at the specified position.
 * Finally, it ensures the modified source string is null-terminated.
 *
 * Note: The caller must ensure that the source string has enough space to accommodate the inserted string.
 * This function does not perform any memory allocation or resizing.
 *
 * @param source The string into which the insert string will be inserted. This string should be large enough to hold the resulting string.
 * @param insert The string to be inserted into the source string.
 * @param position The position in the source string where the insert string should be inserted. The first character is at position 0.
 */
void insertString(char* source, char* insert, int position)
{
    if (source != NULL && insert != NULL)
    {
        int source_len = strlen(source);
        int insert_len = strlen(insert);

        if (position >= 0 && position <= source_len)
        {
            // Shift the part of the source string that comes after the insertion point
            for (int i = source_len; i >= position; i--)
                source[i + insert_len] = source[i];

            // Insert the new string
            for (int i = 0; i < insert_len; i++)
                source[position + i] = insert[i];

            // Null-terminate the new string
            source[source_len + insert_len] = '\0';
        }
    }
}

int main()
{
	char original[200] = { 0 };
	char source[200] = { 0 };
	char insert[200] = { 0 };
	char expected[200] = { 0 };
	int position;

	// Test 1 - Insert "per" into "the wrong son" at position 10 (from the original exercise example).
	strcpy(original, "the wrong son");
	strcpy(source, "the wrong son");
	strcpy(insert, "per");
	strcpy(expected, "the wrong person");
    position = 10;
    insertString(source, insert, position);
	printf("Test 1 - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n", 
		original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 2 -Insert "Hello " at the beginning of "world!".
    strcpy(original, "world!");
    strcpy(source, "world!");
    strcpy(insert, "Hello ");
    strcpy(expected, "Hello world!");
    position = 0;
    insertString(source, insert, position);
    printf("Test 2 - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n",
        original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 3 - Insert "end." at the end of "This is the ".
    strcpy(original, "This is the ");
    strcpy(source, "This is the ");
    strcpy(insert, "end.");
    strcpy(expected, "This is the end.");
    position = 12;
    insertString(source, insert, position);
    printf("Test 3 - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n",
        original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 4 - Insert an empty string into "Nothing changes here".
    strcpy(original, "Nothing changes here");
    strcpy(source, "Nothing changes here");
    strcpy(insert, "");
    strcpy(expected, "Nothing changes here");
    position = 8;
    insertString(source, insert, position);
    printf("Test 4 - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n",
        original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 5 - Insert "amazing " into "This is an test" at position 11.
    strcpy(original, "This is an test");
    strcpy(source, "This is an test");
    strcpy(insert, "amazing ");
    strcpy(expected, "This is an amazing test");
    position = 11;
    insertString(source, insert, position);
    printf("Test 5 - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n",
        original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 6 - Insert " and programming" into "I love C" at position 8.
    strcpy(original, "I love C");
    strcpy(source, "I love C");
    strcpy(insert, " and programming");
    strcpy(expected, "I love C and programming");
    position = 8;
    insertString(source, insert, position);
    printf("Test 6 - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n",
        original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 7 - Insert "fine " into "All is well" at position 4.
    strcpy(original, "All is well");
    strcpy(source, "All is well");
    strcpy(insert, "fine ");
    strcpy(expected, "All fine is well");
    position = 4;
    insertString(source, insert, position);
    printf("Test 7 - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n",
        original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 8 - Insert "Start: " into an empty string.
    strcpy(original, "");
    strcpy(source, "");
    strcpy(insert, "Start: ");
    strcpy(expected, "Start: ");
    position = 0;
    insertString(source, insert, position);
    printf("Test 8 - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n",
        original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 9a - Sequentially insert "quick " and "brown " into "The fox jumps over the lazy dog" (multiple insertions).
    strcpy(original, "The fox jumps over the lazy dog");
    strcpy(source, "The fox jumps over the lazy dog");
    strcpy(insert, "quick ");
    strcpy(expected, "The quick fox jumps over the lazy dog");
    position = 4;
    insertString(source, insert, position);
    printf("Test 9a - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n",
        original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 9b - Continue test 9 with the second insertion
    strcpy(insert, "brown ");
    strcpy(expected, "The quick brown fox jumps over the lazy dog");
    position = 10;
    insertString(source, insert, position);
    printf("Test 9b - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n",
        original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 10 - Insert "!@#" into "HelloWorld" at position 5.
    strcpy(original, "HelloWorld");
    strcpy(source, "HelloWorld");
    strcpy(insert, "!@#");
    strcpy(expected, "Hello!@#World");
    position = 5;
    insertString(source, insert, position);
    printf("Test 10 - source: [%s], insert: [%s], expected: [%s], result: [%s] - [%s]\n",
        original, insert, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

	return 0;
}
