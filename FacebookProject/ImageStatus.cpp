#include "ImageStatus.h"

//c'tor
ImageStatus::ImageStatus(const string& img)
{
	this->img = img;
}

//copy c'tor
ImageStatus::ImageStatus(const ImageStatus& other) : Status(other)
{
	*this = other;
}


//show
void ImageStatus::showStatus() const
{
	Status::showStatus();
	cout << "The status type is: IMAGE\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)this->color);
	cout << img << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)Status::LIGHTGREY);
}

//operator== - between the img
bool ImageStatus::operator==(const Status& other) const
{
	const ImageStatus* temp = dynamic_cast<const ImageStatus*>(&other);
	if (temp)
		return img != temp->img;
	else
		return false;
}

//operator= that gets ImageStatus
const ImageStatus& ImageStatus::operator=(const ImageStatus& other)
{
	if (this != &other)
	{
		this->img = other.img;
		date = other.date;
		time = other.time;
	}
	return *this;
}


//operator= that gets Status
const Status& ImageStatus::operator=(const Status& other)
{
	if (this != &other)
	{
		const ImageStatus* temp = dynamic_cast<const ImageStatus*>(&other);
		if (temp)
			*this = *temp;
	}

	return *this;
}


