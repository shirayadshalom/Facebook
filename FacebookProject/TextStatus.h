#ifndef __TXETSTATUS_H
#define __TXETSTATUS_H
#include "Status.h"
#include <string>

class TextStatus : virtual public Status
{
 protected:
	 string txt;

public:
	TextStatus(const string& txt);
	TextStatus(const TextStatus& other);
	virtual ~TextStatus(){}

	const TextStatus& operator=(const TextStatus& other);
	virtual const Status& operator=(const Status& other) override;
	virtual void showStatus() const override;
	virtual bool operator==(const Status& other) const override;
};
#endif