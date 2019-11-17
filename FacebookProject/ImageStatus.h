#ifndef __IMAGESTATUS_H
#define __IMAGESTATUS_H

#include "Status.h"
#include <string>

class ImageStatus : virtual public Status
{
	protected:
		string img;
		Status::eColor color = Status::BLUE;
	public:
	ImageStatus(const string& img);
	ImageStatus(const ImageStatus& other);
	virtual ~ImageStatus(){}

	const ImageStatus& operator=(const ImageStatus& other);
	virtual const Status& operator=(const Status& other) override;
	virtual void showStatus() const override;
	virtual bool operator==(const Status& other) const override;

};
#endif