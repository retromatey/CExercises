// Exercise 10.11
// 
// Given the definition of a date structure as defined in this chapter, write a 
// function called dateUpdate() that takes a pointer to a date structure as its 
// argument and that updates the structure to the following day (see Program 8.4).
//
// Kochan, Stephen G. Programming in C, Fourth Edition

#include <stdio.h>
#include <stdbool.h>

struct  date
{
	int month;
	int day;
	int year;
};

bool isLeapYear(struct date* d)
{
	bool leapYearFlag;

	if ((d->year % 4 == 0 && d->year % 100 != 0) || d->year % 400 == 0)
		leapYearFlag = true;   // It's a leap year
	else
		leapYearFlag = false;  // Not a leap year

	return leapYearFlag;
}

int numberOfDays(struct date* d)
{
	int days;
	const int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (isLeapYear(d) && d->month == 2)
		days = 29;
	else
		days = daysPerMonth[d->month - 1];

	return days;
}

void dateUpdate(struct date* today)
{
	if (today->day != numberOfDays(today)) 
	{
		today->day = today->day + 1;
		today->month = today->month;
		today->year = today->year;
	}
	else if (today->month == 12)
	{   // end of year
		today->day = 1;
		today->month = 1;
		today->year = today->year + 1;
	}
	else 
	{   // end of month
		today->day = 1;
		today->month = today->month + 1;
		today->year = today->year;
	}
}

void run_test(int month, int day, int year)
{
	printf("************************\n");
	struct date d;
	d.day = day;
	d.month = month;
	d.year = year;
	printf("First date is %i/%i/%.2i.\n", d.month, d.day, d.year % 100);
	dateUpdate(&d);
	printf("Next date is %i/%i/%.2i.\n", d.month, d.day, d.year % 100);
}

int main(void)
{
	run_test(10, 8, 2024);
	run_test(12, 31, 2024);
	run_test(2, 28, 2024);
	run_test(2, 28, 2023);

	//struct date day;

	//printf("Enter today's date (mm dd yyyy): ");

	//if (scanf("%i%i%i", &day.month, &day.day, &day.year))
	//{
	//	dateUpdate(&day);
	//	printf("Tomorrow's date is %i/%i/%.2i.\n", day.month, day.day, day.year % 100);
	//}

	return 0;
}