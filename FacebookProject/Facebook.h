#ifndef __FACEBOOK_H
#define __FACEBOOK_H
#include "Date.h"
#include "User.h"
#include "Status.h"
#include "FansPage.h"
#include "Friend.h"
#include <string>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

class Facebook
{
private:
	static const int FRIEND = 1, FAN_PAGE = 2;
	vector<User*> users;

	void addToUsers(User* newUser);
	
	public:
		Facebook() = default;
		//copy c'tor
		Facebook(const Facebook&) = delete;
		~Facebook();

		const Facebook& operator=(const Facebook& other) = delete;
		void addNewFriend(const string& name, const Date& birthday);
		void addNewFansPage(const string& name);
		void addNewStatus(const string& name, int flag, Status* newStatus);
		void showAllStatus(const string& name, int flag) const;
		void makeFriendship(const string& nameOne, const string& nameTwo);
		void addNewFan(const string& friendName, const string& fansPageName);
		void showAll() const;
		void showAllFriends(const string& name, int flag) const;
		void show10Statuses(const string& name) const;
		Friend* isFriendExist(const string& name) const;
		FansPage* isFansPageExist(const string& name) const;
};

#endif 

