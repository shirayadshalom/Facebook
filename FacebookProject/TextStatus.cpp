#include "TextStatus.h"

//c'tor
TextStatus::TextStatus(const string& txt)
{
	this->txt = txt;
}

//copy c'tor
TextStatus::TextStatus(const TextStatus& other) : Status(other)
{
	*this = other;
}

//show
void TextStatus::showStatus() const
{
	Status::showStatus();
	cout << "The status type is: TEXT\n";
	cout << txt << "\n\n";
}

//operator== - between the img
bool TextStatus::operator==(const Status& other) const
{
	const TextStatus* temp = dynamic_cast<const TextStatus*>(&other);
	if (temp)
		return txt != temp->txt;
	else
		return false;
}


//operator= that gets TextStatus
const TextStatus& TextStatus::operator=(const TextStatus& other)
{
	if (this != &other)
	{
		this->txt = other.txt;
		date = other.date;
		time = other.time;
	}
	return *this;
}

//operator= that gets Status
const Status& TextStatus::operator=(const Status& other)
{
	if (this != &other)
	{
		const TextStatus* temp = dynamic_cast<const TextStatus*>(&other);
		if (temp)
			*this = *temp;
	}

	return *this;
}