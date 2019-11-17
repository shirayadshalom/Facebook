#include "TextImageStatus.h"

//show
void TextImageStatus::showStatus() const
{
	Status::showStatus();
	cout << "The status type is: TEXT AND IMAGE\n";
	cout << txt << "\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)this->color);
	cout << img << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)Status::LIGHTGREY);

}

//operator== - between the img and txt
bool TextImageStatus::operator==(const Status& other) const
{
	const TextImageStatus* temp = dynamic_cast<const TextImageStatus*>(&other);
	if (temp)
		return TextStatus::operator==(other) && ImageStatus::operator==(other);
	else
		return false;
}

//operator= that gets Status
const Status& TextImageStatus::operator=(const Status& other)
{
	if (this != &other)
	{
		const TextImageStatus* temp = dynamic_cast<const TextImageStatus*>(&other);
		if (temp)
		{
			TextStatus::operator=(other);
			ImageStatus::operator=(other);
		}
	}

	return *this;
}