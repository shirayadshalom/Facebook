#ifndef __DATE_H
#define __DATE_H
#include <time.h>
#include <iostream>
using namespace std;

class Date
{
	int day;
	int month;
	int year;

public:
	//c'tor
	Date(int day, int month, int year) : day(day), month(month), year(year) {}
	Date();

	//getters
	int getDay() { return this->day; }
	int getMonthe() { return this->month; }
	int getYear() { return this->year; }

	void showDate(void) const;
	int friend compareDates(const Date& d1, const Date& d2);
};

#endif