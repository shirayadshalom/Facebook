#ifndef __VIDEOSTATUS_H
#define __VIDEOSTATUS_H
#include "Status.h"
#include <string>

class VideoStatus : virtual public Status
{
protected:
	string video;
	Status::eColor color = Status::YELLOW;
public:
	VideoStatus(const string& video);
	VideoStatus(const VideoStatus& other);
	virtual ~VideoStatus(){}

	const VideoStatus& operator=(const VideoStatus& other);
	virtual const Status& operator=(const Status& other) override;
	virtual void showStatus() const override;
	virtual bool operator==(const Status& other) const override;
};
#endif