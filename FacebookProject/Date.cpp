#include "Date.h"

//c'tor
Date::Date() {
	time_t now = time(0);
	tm * ltm = localtime(&now);
	day = ltm->tm_mday;
	month = 1 + ltm->tm_mon;
	year = 1900 + ltm->tm_year;
}

//This method show the current date
void Date::showDate(void) const {
	cout << "Current date " << this->day << "/" << this->month << "/" << this->year;
}

//This function compare between two Times and return 1 if d1 is after d2,
//return 0 if d1=d2, return -1 if d2 is after d1
int compareDates(const Date& d1, const Date& d2)
{
	if (d1.year > d2.year || (d1.year == d2.year && d1.month > d2.month)
		|| (d1.year == d2.year && d1.month == d2.month && d1.day > d2.day))
		return 1;
	if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day)
		return 0;
	return -1;
}