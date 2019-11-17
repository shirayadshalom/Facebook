#include "VideoStatus.h"

//c'tor
VideoStatus::VideoStatus(const string& video) 
{
	this->video = video;
}

//copy c'tor
VideoStatus::VideoStatus(const VideoStatus& other) : Status(other)
{
	*this = other;
}


//show
void VideoStatus::showStatus() const
{
	Status::showStatus();
	cout << "The status type is: VIDEO\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)this->color);
	cout << video << "\n\n";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (int)Status::LIGHTGREY);
}

//operator== - between the video
bool VideoStatus::operator==(const Status& other) const
{
	const VideoStatus* temp = dynamic_cast<const VideoStatus*>(&other);
	if (temp)
		return video != temp->video;
	else
		return false;
}

//operator= that gets VideoStatus
const VideoStatus& VideoStatus::operator=(const VideoStatus& other)
{
	if (this != &other)
	{
		this->video = other.video;
		date = other.date;
		time = other.time;
	}
	return *this;
}

//operator= that gets Status
const Status& VideoStatus::operator=(const Status& other)
{
	if (this != &other)
	{
		const VideoStatus* temp = dynamic_cast<const VideoStatus*>(&other);
		if (temp)
			*this = *temp;
	}

	return *this;
}