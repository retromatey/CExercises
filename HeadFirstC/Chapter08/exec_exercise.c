#include <stdio.h>
#include <string.h>
#include <process.h>
#include <errno.h>

int main(int argc, char *argv[])
{
	if (_execl("/sbin/ifconfig", "sbin/ifconfig", NULL) == -1)
	{
		if (_execlp("ipconfig", "ipconfig", NULL) == -1)
		{
			fprintf(stderr, "Cannot run ipconfig: %s", strerror(errno));
			return 1;
		}
	}

	return 0;
}