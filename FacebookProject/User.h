#ifndef __USER_H
#define __USER_H

#include "Status.h"
#include <string.h>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class User
{
protected:
	string name;
	vector<User*> users;
	vector<Status*> statuses;

public:
	User(const string& name);
	User(const User& other) = delete;
	virtual ~User();

	const User& operator=(const User& other) = delete;
	const string& getName() const { return name; }
	const vector<User*>& getUsers() const { return users; }
	void showStatuses() const;
	void addStatus(Status* newStatus);
	bool addUser(User* newUser, int& flag);
	virtual void showUsers() const;
	virtual void show() const;
	bool isUserExist(User* toFind);
	User& operator+=(User& other);
	virtual bool operator>(const User& other) const;

};
#endif 