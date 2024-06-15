// Write a program that will allow a list of words to be entered separated by commas, and then 
// extract the words and output them one to a line, removing any leading or trailing spaces.
// For example, if the input is 
// 
// John, Jack, Jill 
// 
// then the output will be 
// 
// John
// Jack 
// Jill

// Ivor Horton. Beginning C: From Novice to Professional, Fourth Edition(p. 240). Kindle Edition.

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 200

int main()
{
	char input[MAX_INPUT];
	int letter_index = 0;

	printf("Type a list of words separated by commas.\n");	
	fgets(input, sizeof(input), stdin);

	while (input[letter_index] != '\n' && letter_index < MAX_INPUT)
	{
		if (input[letter_index] == ',')
			printf("\n");
		else if (input[letter_index] != ' ')
			printf("%c", input[letter_index]);

		letter_index++;
	}

	return 0;
}

// Issues:
// - Spaces in the middle of a word are not handled
// - fgets reads the trailing newline, which is not needed for processing
// - Consecutive commas might cause problems




// AI version
/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 200

void trim_spaces(char *str) {
    // Trim leading spaces
    while(*str == ' ') {
        str++;
    }

    // Find end of string
    char *end = str + strlen(str) - 1;

    // Trim trailing spaces
    while(end > str && *end == ' ') {
        end--;
    }

    // Write new null terminator
    *(end + 1) = '\0';
}

int main() {
    char input[MAX_INPUT];
    char *token;

    printf("Type a list of words separated by commas:\n");
    fgets(input, sizeof(input), stdin);

    // Remove trailing newline character from fgets
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    // Tokenize the input string
    token = strtok(input, ",");

    while (token != NULL) {
        // Trim leading and trailing spaces from the token
        trim_spaces(token);
        printf("%s\n", token);
        token = strtok(NULL, ",");
    }

    return 0;
}
*/