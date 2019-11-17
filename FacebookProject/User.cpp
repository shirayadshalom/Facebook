#include "User.h"

//c'tor
User::User(const string& name)
{
	this->name = name;
}

//d'tor
User::~User()
{
	vector<Status*>::const_iterator itr = statuses.begin();
	vector<Status*>::const_iterator itrEnd = statuses.end();
	for (; itr != itrEnd; ++itr)
		delete (*itr);
}

//show
void User::show() const {

	cout << name << endl;
}

//This method add new status to the board
void User::addStatus(Status* newStatus)
{
	int logSize = statuses.size(), phySize = statuses.capacity();

	if (logSize == 0)
		statuses.reserve(2);

	else if (logSize == phySize)
		statuses.reserve(2 * phySize);

	statuses.push_back(newStatus);
}

//This method show all the User  statuses
void User::showStatuses() const {

	int logSize = statuses.size();
	vector<Status*>::const_iterator itr = statuses.begin();
	vector<Status*>::const_iterator itrEnd = statuses.end();

	if (logSize == 0)
		cout << "No statuses to show\n";
	else
	{
		for (; itr != itrEnd; ++itr)
			(*itr)->showStatus();
	}
}

//This method add new friend 
bool User::addUser(User* newUser, int& flag) {
	
	int logSize = users.size(), phySize = users.capacity();

	if (newUser == this)
	{
		flag = 1;
		return false;
	}
	//cheack that the user is not already exist
	else if (!isUserExist(newUser))
	{
		if (logSize == 0)
			users.reserve(2);

		else if (logSize == phySize)
			users.reserve(2 * phySize);

		users.push_back(newUser);
		newUser->addUser(this, flag);
		return true;
	}
	else
	{
		flag = 0;
		return false;
	}		
}

//This method show all the friends
void User::showUsers() const {

	int logSize = users.size();
	vector<User*>::const_iterator itr = users.begin();
	vector<User*>::const_iterator itrEnd = users.end();

	if (logSize == 0)
		cout << "No users to show\n";
	else
	{
		for (; itr != itrEnd; ++itr)
			(*itr)->show();
	}
}

//This method return true if toFind is in users
bool User::isUserExist(User* toFind)
{
	int logSize = users.size();
	vector<User*>::const_iterator itr = users.begin();
	vector<User*>::const_iterator itrEnd = users.end();

	for (; itr != itrEnd; ++itr)
	{
		if(toFind == (*itr))
			return true;
	}
		
	return false;
}


//Operator overload - other is not const becuse it change - return is not const to allow y+=x+=z
User& User::operator+=(User& other)
{
	int flag;
	bool s = addUser(&other, flag);
	if (!s)
	{
		if (flag)
			cout << "You can't add yourself!\n";
		else
			cout << "The users already connected\n";
	}
	return *this;
}

//This method compere between the number of the users
bool User::operator>(const User& other) const
{
	return (users.size() > other.users.size());
}