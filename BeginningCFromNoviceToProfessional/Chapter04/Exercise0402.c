// Write a program that will output the printable characters for character code values from 0 to 127. 
// Output each character code along with its symbol with two characters to a line. Make sure the 
// columns are aligned. (Hint: You can use the isgraph () function that's declared in ctype.h to 
// determine when a character is printable.)

// Ivor Horton.Beginning C : From Novice to Professional, Fourth Edition(p. 173).Kindle Edition.


#include <stdio.h>
#include <ctype.h>

int main() 
{
	int min_code = 0;
	int max_code = 127;

	for (int i = min_code; i <= max_code; i++)
	{
		if (isgraph(i))
		{
			printf("%3d - %c\n", i, i);
		}
	}

	return 0;
}