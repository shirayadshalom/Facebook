#ifndef __STATUS_H
#define __STATUS_H
#include <conio.h>
#include <windows.h>

#include "Date.h"
#include <string.h>
#include "Time.h"

class Status
{
public:
	enum eColor{BLUE = 1, YELLOW = 14, LIGHTGREY = 7};

protected:
	Date date;
	Time time;
	
public:
	Status() = default;
	//d'tor
	virtual ~Status() {};

	virtual const Status& operator=(const Status& other) = 0;
	virtual void showStatus() const = 0 {
			cout << "Date of status: ";
			this->date.showDate();
			cout << "\nTime of status: ";
			this->time.showTime();
	}
	const Date& getDate() const { return date; }
	const Time& getTime() const { return time; }
	virtual bool operator==(const Status& other) const = 0;
	virtual bool operator!=(const Status& other) const { return !(*this == other); }
};

class ltStatus
{
public:
	// This function compare between two dates and times of the statuses
	bool operator()(const Status* s1, const Status* s2) const
	{
		int dateCompares = compareDates(s1->getDate(), s2->getDate());
		//same day
		if (dateCompares == 0)
			return compareTime(s1->getTime(), s2->getTime()) < 0;
		return dateCompares < 0;
	}
};

#endif