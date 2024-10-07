// Exercise 10.9
// 
// Rewrite the readLine() function from Chapter 9 so that it uses a character pointer rather than an array.
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>

//// Original version from Chapter 9
//void readLine(char buffer[])
//{
//    char character;
//    int i = 0;
//
//    do
//    {
//        character = getchar();
//        buffer[i] = character;
//        ++i;
//    } while (character != '\n');
//
//    buffer[i - 1] = '\0';
//}

void readLine(char* ptr, int length)
{
    int character;
    char* ptrEnd = ptr + length;

    do
    {
        character = getchar();
        *ptr++ = (char)character;
        //ptr++;
    } while (character != '\n' && ptr < ptrEnd);

    *ptr = '\0';
}

void test(void)
{
    printf("Testing readLine()\n");
    char buffer[200] = { 0 };
    char* ptr = buffer;
    readLine(ptr, 200);
    printf("buffer: %s\n", buffer);
}

int main(void)
{
    test();
	return 0;
}