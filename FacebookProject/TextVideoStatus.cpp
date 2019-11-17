#include "TextVideoStatus.h"

//show
void TextVideoStatus::showStatus() const
{
	Status::showStatus();
	cout << "The status type is: TEXT AND IMAGE\n";
	cout << txt << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)this->color);
	cout << video << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)Status::LIGHTGREY);
}

////operator== - between the video and txt
bool TextVideoStatus::operator==(const Status& other) const
{
	const TextVideoStatus* temp = dynamic_cast<const TextVideoStatus*>(&other);
	if (temp)
		return TextStatus::operator==(other) && VideoStatus::operator==(other);
	else
		return false;
}

//operator= that gets Status
const Status& TextVideoStatus::operator=(const Status& other)
{
	if (this != &other)
	{
		const TextVideoStatus* temp = dynamic_cast<const TextVideoStatus*>(&other);
		if (temp)
		{
			TextStatus::operator=(other);
			VideoStatus::operator=(other);
		}
	}

	return *this;
}