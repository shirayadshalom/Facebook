#ifndef __TXTVIDEOSTATUS_H
#define __TXTVIDEOTATUS_H
#include "Status.h"
#include "VideoStatus.h"
#include "TextStatus.h"

class TextVideoStatus : public TextStatus, public VideoStatus
{
public:
	TextVideoStatus(const TextStatus& ts, const VideoStatus& vs) : TextStatus(ts), VideoStatus(vs) {}
	
	void showStatus() const override;
	virtual bool operator==(const Status& other) const override;
	virtual const Status& operator=(const Status& other) override;
};
#endif