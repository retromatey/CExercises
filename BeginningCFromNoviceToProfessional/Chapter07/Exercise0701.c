// Exercise 7-1. Write a program to calculate the average for an arbitrary number of 
// floating-point values that are entered from the keyboard. Store all values in memory 
// that's allocated dynamically before calculating and displaying the average. The user 
// shouldn't be required to specify in advance how many values there will be.

// Ivor Horton. Beginning C : From Novice to Professional, Fourth Edition (p. 294). Kindle Edition.

#include <stdio.h>
#include <stdlib.h>

typedef struct _data {
	float input_num;
	struct _data* next;
} Data;

Data* create(float num)
{
	Data* data = malloc(sizeof(Data));

	if (data != NULL)
	{
		data->input_num = num;
		data->next = NULL;
		return data;
	}

	return NULL;
}

void release(Data* data)
{
	Data* i = data;
	Data* next = NULL;

	for (; i != NULL; i = next)
	{
		next = i->next;
		free(i);
	}
}

Data* get_input()
{
	Data* start = NULL;
	Data* next = NULL;
	float input;

	while (fscanf(stdin, "%f", &input) > 0)
	{
		Data* entry = create(input);

		if (entry != NULL)
		{
			if (start == NULL)
			{
				start = entry;
				next = start;
			}
			else
			{
				next->next = entry;
				next = next->next;
			}
		}
		else
		{
			printf("Error creating Data struct\n");
			exit(1);
		}
	}

	return start;
}

float average(Data* data)
{
	float acc = 0.0f;
	int count = 0;

	Data* next = data;
	while (next != NULL)
	{
		acc += next->input_num;
		count++;
		next = next->next;
	}

	return acc / count;
}

int main(int argc, char *argv[])
{
	Data* start = get_input();
	float avg = average(start);
	release(start);

	printf("Avg is %.2f\n", avg);

	return 0;
}