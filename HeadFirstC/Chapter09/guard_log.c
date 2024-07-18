#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* now()
{
	time_t t;
	time(&t);
	return asctime(localtime(&t));
}

int main(int argc, char *argv[])
{
	char comment[80];
	char cmd[120];

	fgets(comment, 80, stdin);
	sprintf(cmd, "echo '%s %s' >> reports.log", comment, now());

	// Remove all newline characters from cmd
	for (int i = 0; cmd[i] != '\0'; ++i) {
		if (cmd[i] == '\n') {
			// Shift the rest of the characters one position to the left
			for (int j = i; cmd[j] != '\0'; ++j) {
				cmd[j] = cmd[j + 1];
			}
			// Decrement i to check the new character at this position
			i--;
		}
	}

	system(cmd);

	return 0;
}