#include <stdio.h>
#include <stdlib.h>
#include <process.h>

int main(int argc, char *argv[])
{
	char* my_env[] = { "JUICE=peach and apple", NULL };
	_execle("diner_info.exe", "dine_info.exe", "4", NULL, my_env);

	return 0;
}