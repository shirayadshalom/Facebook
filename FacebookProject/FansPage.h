#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include "User.h"
#include "Friend.h"
#include <string>
class FansPage : public User
{

public:
	FansPage(const string& name) : User(name){}
	//copy c'tor
	FansPage(const FansPage& other) = delete;

	const FansPage& operator=(const FansPage& other) = delete;
	void show() const override;
	virtual bool operator>(const User& other) const;

};

#endif
