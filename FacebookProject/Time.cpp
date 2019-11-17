#include "Time.h"

//c'tor
Time::Time()
{
	time_t now = time(0);
	tm * ltm = localtime(&now);
	hours = ltm->tm_hour;
	min = ltm->tm_min;
	sec = ltm->tm_sec;
}

//This method show the curr time
void Time::showTime(void) const {
	if (hours < 10)
		cout << "0" << "" << hours << ":";
	else
		cout << hours << ":";
	if (min < 10)
		cout << "0" << "" << min << ":";
	else
		cout << min << ":";
	if (sec < 10)
		cout << "0" << "" << sec << "\n";
	else
		cout << sec << "\n";
}

//This function compare between two Times and return 1 if t1 is after t2,
//return 0 if t1=t2, return -1 if t2 is after t1
int compareTime(const Time& t1, const Time& t2)
{
	if ((t1.hours > t2.hours) || (t1.hours == t2.hours && t1.min > t2.min)
		|| (t1.hours == t2.hours && t1.min == t2.min && t1.sec > t2.sec))
		return 1;
	if (t1.hours == t2.hours && t1.min == t2.min && t1.sec == t2.sec)
		return 0;
	return -1;
}