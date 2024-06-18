// Write a function called substring to extract a portion of a character string. The function 
// should be called as follows: 
// 
//     substring (source, start, count, result); 
// 
// where source is the character string from which you are extracting the substring, start is 
// an index number into source indicating the first character of the substring, count is the 
// number of characters to be extracted from the source string, and result is an array of 
// characters that is to contain the extracted substring. For example, the call 
// 
//     substring ("character", 4, 3, result); 
// 
// extracts the substring "act" (three characters starting with character number 4) from the 
// string "character" and places the result in result. Be certain the function inserts a null 
// character at the end of the substring in the result array. Also, have the function check 
// that the requested number of characters does, in fact, exist in the string. If this is not 
// the case, have the function end the substring when it reaches the end of the source string. 
// So, for example, a call such as 
// 
//     substring ("two words", 4, 20, result); 
// 
// should just place the string “words” inside the result array, even though 20 characters 
// were requested by the call.

// Kochan, Stephen G. Programming in C (pp. 379 - 380). Pearson Education. Kindle Edition.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Extracts a substring from a given source string.
 *
 * This function copies a portion of the source string starting from a specified index (start)
 * and spanning a specified number of characters (count) into a result array. The extracted
 * substring is null-terminated. If the requested number of characters extends beyond the end
 * of the source string, the function will only copy characters up to the end of the source string.
 *
 * @param source The source string from which to extract the substring.
 * @param start  The starting index in the source string from which to begin extraction.
 * @param count  The number of characters to extract from the source string.
 * @param result The array to store the extracted substring. Must be large enough to hold the substring plus a null terminator.
 */
void substring(const char* source, int start, int count, char* result)
{
	int len = strlen(source);

	if (start < len && start >= 0 && count >= 0)
	{
		int end = start + count;
		int source_index = start;
		int result_index = 0;

		while (source_index < len && source_index < end)
		{
			result[result_index] = source[source_index];
			result_index++;
			source_index++;
		}

		result[result_index] = '\0';
	}
	else
	{
		result[0] = '\0';
	}
}

/**
 * Clears the contents of the result array.
 *
 * @param result The array to be cleared.
 * @param resultSize The size of the result array.
 */
void clear(char* result, size_t resultSize)
{
	for (size_t i = 0; i < resultSize; i++)
		result[i] = '\0';
}

int main()
{
	char result[200];

	clear(result, sizeof(result));
	substring("character", 4, 3, result);
	printf("%s\n", result);

	clear(result, sizeof(result));
	substring("two words", 4, 20, result);
	printf("%s\n", result);

    // Test case 1
    clear(result, sizeof(result));
    substring("hello world", 6, 5, result);
    printf("%s\n", result);  // Expected output: "world"

    // Test case 2
    clear(result, sizeof(result));
    substring("C programming", 2, 11, result);
    printf("%s\n", result);  // Expected output: "programming"

    // Test case 3
    clear(result, sizeof(result));
    substring("test string", 0, 4, result);
    printf("%s\n", result);  // Expected output: "test"

    // Test case 4
    clear(result, sizeof(result));
    substring("edge case", 8, 5, result);
    printf("%s\n", result);  // Expected output: "e" (only one character since start index is at the last character)

    // Test case 5
    clear(result, sizeof(result));
    substring("short", 0, 10, result);
    printf("%s\n", result);  // Expected output: "short" (count exceeds length of string)

    // Test case 6
    clear(result, sizeof(result));
    substring("boundary test", -1, 5, result);
    printf("%s\n", result);  // Expected output: "" (invalid start index)

    // Test case 7
    clear(result, sizeof(result));
    substring("negative count", 4, -3, result);
    printf("%s\n", result);  // Expected output: "" (negative count)

    // Test case 8
    clear(result, sizeof(result));
    substring("empty string", 0, 0, result);
    printf("%s\n", result);  // Expected output: "" (count is zero)

    // Test case 9
    clear(result, sizeof(result));
    substring("multiple words here", 8, 6, result);
    printf("%s\n", result);  // Expected output: " words"

    // Test case 10
    clear(result, sizeof(result));
    substring("abcdefghijklmnopqrstuvwxyz", 5, 10, result);
    printf("%s\n", result);  // Expected output: "fghijklmno"

	return 0;
}
