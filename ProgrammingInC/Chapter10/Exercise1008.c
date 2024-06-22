// Using the findString, removeString, and insertString functions from preceding 
// exercises, write a function called replaceString that takes three character 
// string arguments as follows
//
//     replaceString (source, s1, s2);
//
// and that replaces s1 inside source with the character string s2. The function 
// should call the findString function to locate s1 inside source, then call the 
// removeString function to remove s1 from source, and finally call the insertString 
// function to insert s2 into source at the proper location. So, the function call
//
//     replaceString (text, "1", "one");
//
// replaces the first occurrence of the character string "1" inside the character 
// string text, if it exists, with the string "one". Similarly, the function call
//
//    replaceString (text, "*", "");
//
// has the effect of removing the first asterisk inside the text array because the 
// replacement string is the null string.

// Kochan, Stephen G. Programming in C (p. 382). Pearson Education. Kindle Edition.
// Exercise1008.c


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
                //text[start + 1] = '\0';  // If count exceeds the remaining characters, just terminate at start
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
        }
    }

    return -1;
}

/**
 * Replaces the first occurrence of a substring in a source string with another string.
 *
 * This function takes a source string and replaces the first occurrence of a specified substring (s1)
 * with another string (s2). It first calls the findString function to locate the position of s1 in the source string.
 * Then, it calls the removeString function to remove s1 from the source string.
 * Finally, it calls the insertString function to insert s2 into the source string at the proper location.
 *
 * @param source The source string in which the replacement will be performed.
 * @param s1 The substring to be replaced in the source string.
 * @param s2 The string to replace the first occurrence of s1 in the source string.
 */
void replaceString(char* source, char* s1, char* s2)
{
    int position = findString(source, s1);
    int s1_len = strlen(s1);
    removeString(source, position, s1_len);
    insertString(source, s2, position);
}

int main(int argc, char* argv[])
{
    char source[200] = { 0 };
    char original[200] = { 0 };
    char expected[200] = { 0 };
    char s1[200] = { 0 };
    char s2[200] = { 0 };

    // Test 1 - Replace '1' with 'one' in the string 'This is the 1'
    strcpy(source, "This is the 1");
    strcpy(original, "This is the 1");
    strcpy(expected, "This is the one");
    strcpy(s1, "1");
    strcpy(s2, "one");
    replaceString(source, s1, s2);
    printf("Test 1 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 2 - Replace 'is' with 'was' in the string 'This is a test'
    strcpy(source, "This is a test");
    strcpy(original, "This is a test");
    strcpy(expected, "This was a test");
    strcpy(s1, " is");
    strcpy(s2, " was");
    replaceString(source, s1, s2);
    printf("Test 2 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 3 - Replace 'test' with 'exam' in the string 'This is a test'
    strcpy(source, "This is a test");
    strcpy(original, "This is a test");
    strcpy(expected, "This is a exam");
    strcpy(s1, "test");
    strcpy(s2, "exam");
    replaceString(source, s1, s2);
    printf("Test 3 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 4 - Replace ' ' with '_' in the string 'Space test'
    strcpy(source, "Space test");
    strcpy(original, "Space test");
    strcpy(expected, "Space_test");
    strcpy(s1, " ");
    strcpy(s2, "_");
    replaceString(source, s1, s2);
    printf("Test 4 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 5 - Replace 'the' with 'a' in the string 'This is the test'
    strcpy(source, "This is the test");
    strcpy(original, "This is the test");
    strcpy(expected, "This is a test");
    strcpy(s1, "the");
    strcpy(s2, "a");
    replaceString(source, s1, s2);
    printf("Test 5 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 6 - Replace 'cat' with 'dog' in the string 'The cat sat on the mat'
    strcpy(source, "The cat sat on the mat");
    strcpy(original, "The cat sat on the mat");
    strcpy(expected, "The dog sat on the mat");
    strcpy(s1, "cat");
    strcpy(s2, "dog");
    replaceString(source, s1, s2);
    printf("Test 6 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 7 - Replace 'quick' with 'slow' in the string 'The quick brown fox'
    strcpy(source, "The quick brown fox");
    strcpy(original, "The quick brown fox");
    strcpy(expected, "The slow brown fox");
    strcpy(s1, "quick");
    strcpy(s2, "slow");
    replaceString(source, s1, s2);
    printf("Test 7 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 8 - Replace 'brown' with 'black' in the string 'The quick brown fox'
    strcpy(source, "The quick brown fox");
    strcpy(original, "The quick brown fox");
    strcpy(expected, "The quick black fox");
    strcpy(s1, "brown");
    strcpy(s2, "black");
    replaceString(source, s1, s2);
    printf("Test 8 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 9 - Replace 'fox' with 'wolf' in the string 'The quick brown fox'
    strcpy(source, "The quick brown fox");
    strcpy(original, "The quick brown fox");
    strcpy(expected, "The quick brown wolf");
    strcpy(s1, "fox");
    strcpy(s2, "wolf");
    replaceString(source, s1, s2);
    printf("Test 9 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 10 - Replace 'The' with 'A' in the string 'The quick brown fox'
    strcpy(source, "The quick brown fox");
    strcpy(original, "The quick brown fox");
    strcpy(expected, "A quick brown fox");
    strcpy(s1, "The");
    strcpy(s2, "A");
    replaceString(source, s1, s2);
    printf("Test 10 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 11 - Replace 'This' with 'That' in the string 'This is the 1'
    strcpy(source, "This is the 1");
    strcpy(original, "This is the 1");
    strcpy(expected, "That is the 1");
    strcpy(s1, "This");
    strcpy(s2, "That");
    replaceString(source, s1, s2);
    printf("Test 11 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 12 - Replace 'test' with 'TEST' in the string 'This is a test'
    strcpy(source, "This is a test");
    strcpy(original, "This is a test");
    strcpy(expected, "This is a TEST");
    strcpy(s1, "test");
    strcpy(s2, "TEST");
    replaceString(source, s1, s2);
    printf("Test 12 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 13 - Replace 'on' with 'ON' in the string 'The cat sat on the mat'
    strcpy(source, "The cat sat on the mat");
    strcpy(original, "The cat sat on the mat");
    strcpy(expected, "The cat sat ON the mat");
    strcpy(s1, "on");
    strcpy(s2, "ON");
    replaceString(source, s1, s2);
    printf("Test 13 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 14 - Replace 'a' with 'A' in the string 'This is a test'
    strcpy(source, "This is a test");
    strcpy(original, "This is a test");
    strcpy(expected, "This is A test");
    strcpy(s1, "a");
    strcpy(s2, "A");
    replaceString(source, s1, s2);
    printf("Test 14 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

    // Test 15 - Replace ' ' with '-' in the string 'This is a test'
    strcpy(source, "This is a test");
    strcpy(original, "This is a test");
    strcpy(expected, "This-is a test");
    strcpy(s1, " ");
    strcpy(s2, "-");
    replaceString(source, s1, s2);
    printf("Test 15 - source: [%s], expected: [%s], result: [%s] - %s\n", original, expected, source, strcmp(source, expected) == 0 ? "PASS" : "FAIL");

	return 0;
}
