#include <stdio.h>

typedef struct {
	unsigned int first_visit : 1;	// YES/NO
	unsigned int come_again : 1;	// YES/NO
	unsigned int fingers_lost : 4;	// 10 fingers
	unsigned int shark_attack : 1;	// YES/NO
	unsigned int days_a_week : 3;	// 7 days in a week
} survey;


int main(int argc, char* argv[])
{

	return 0;
}