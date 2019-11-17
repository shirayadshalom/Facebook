#ifndef __FRIEND_H
#define __FRIEND_H
#include "User.h"
#include "Date.h"
#include "FansPage.h"
#include <string>
#include <set>

class Friend : public User
{
	Date birthday;
	int numOfFriends;
	
public:
	//c'tor & d'tor
	Friend(const string& name,const Date& birthday) : User(name), birthday(birthday), numOfFriends(0){}
	Friend(const Friend& other) = delete;

	const Friend& operator=(const Friend& other) = delete;
	virtual void showUsers() const override;
	virtual void show() const override
	{
		cout << "The friend name is: ";
		User::show();
	}
	void setNumOfFriends(int i);
	int getNumOfFriends() const { return numOfFriends; } 
	void showLastFriendsStatus() const;
	virtual bool operator>(const User& other) const override;
};

#endif 
