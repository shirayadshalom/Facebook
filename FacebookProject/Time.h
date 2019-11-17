#ifndef __TIME_H
#define __TIME_H
#include <time.h>
#include <iostream>
using namespace std;


class Time
{
	int hours;
	int min;
	int sec;

public:
	Time();

	//getters
	int getHours() { return this->hours; }
	int getMin() { return this->min; }
	int getSec() { return this->sec; }

	void showTime(void) const;
	int friend compareTime(const Time& t1, const Time& t2);
};

#endif