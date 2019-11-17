#ifndef __TXTIMGSTATUS_H
#define __TXTIMGSTATUS_H
#include "Status.h"
#include "ImageStatus.h"
#include "TextStatus.h"

class TextImageStatus : public TextStatus, public ImageStatus
{
public:
	TextImageStatus(const TextStatus& ts, const ImageStatus& is) : TextStatus(ts), ImageStatus(is) {}
	
	virtual const Status& operator=(const Status& other) override;
	void showStatus() const override;
	virtual bool operator==(const Status& other) const override;
};
#endif

