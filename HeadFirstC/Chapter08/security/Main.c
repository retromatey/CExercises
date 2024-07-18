#include <stdio.h>
#include "encrypt.h"
#include "checksum.h"

int main(int argc, char *argv[])
{
	char s[] = "Speak friend and enter";
	encrypt(s);
	printf("Encrypted to '%s'\n", s);
	printf("Checksum is %i\n", checksum(s));
	encrypt(s);
	printf("Decrypted back to '%s'\n", s);
	printf("Checksum is %i\n", checksum(s));

	return 0;
}