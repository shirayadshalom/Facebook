#include "Facebook.h"

//d'tor
Facebook::~Facebook()
{
	vector<User*>::const_iterator itr = users.begin();
	vector<User*>::const_iterator itrEnd = users.end();

	for (; itr != itrEnd; ++itr)
		delete (*itr);
}

//This method add new friend
void Facebook::addNewFriend(const string& name, const Date& birthday)
{
	Friend* newFriend;
	//check that the name is not taken
	if (isFriendExist(name) == nullptr)
	{
		newFriend = new Friend(name, birthday);
		addToUsers(newFriend);
	}
	else
		cout << "The name is taken\n";
}

//This method add new fans page
void Facebook::addNewFansPage(const string& name)
{
	FansPage* newFansPages;
	//check that the name is not taken
	if (isFansPageExist(name) == nullptr)
	{
		newFansPages = new FansPage(name);
		addToUsers(newFansPages);
	}
	else
		cout << "The name is taken\n";
}

//This method add new status to a friend/fans page
void Facebook::addNewStatus(const string& name, int flag, Status* newStatus)
{
	User* currUser;

	if (flag == FRIEND)
		currUser = isFriendExist(name);
	else
		currUser = isFansPageExist(name);

	if (currUser != nullptr)
		currUser->addStatus(newStatus);
	else
	{
		cout << "The user don't exist\n";
		delete newStatus;
	}
		
}

//This method show all the statuses of a friend/fans page
void Facebook::showAllStatus(const string& name, int flag) const
{
	User* currUser;

	if (flag == FRIEND)
		currUser = isFriendExist(name);
	else
		currUser = isFansPageExist(name);

	if (currUser != nullptr)
		currUser->showStatuses();
	else
		cout << "The user don't exist\n";
}

//This method make friendship between two friends
void Facebook::makeFriendship(const string& nameOne, const string& nameTwo)
{
	bool s;
	int flag;
	Friend* f1 = isFriendExist(nameOne),
		*f2 = isFriendExist(nameTwo);
	if (f1 != nullptr && f2 != nullptr)
	{
		s = f1->addUser(f2, flag);
		if (s)
		{
			f1->setNumOfFriends(1);
			f2->setNumOfFriends(1);
		}
		else
		{
			if(flag)
				cout << "You can't add yourself!\n";
			else
				cout << "The friends already connected\n";
		}
	}	
	else
		cout << "One of the friends is not exist\n";
}

//This method add a friend as a fan of fans page
void Facebook::addNewFan(const string& friendName, const string& fansPageName)
{
	//find the friend and the fans page
	Friend* newFriend = isFriendExist(friendName);
	FansPage* fansPage = isFansPageExist(fansPageName);
	bool s;
	int flag;

	if (newFriend == nullptr)
		cout << "The friend is not exist\n";
	else if (fansPage == nullptr)
		cout << "The fans page is not exist\n";
	else
		*newFriend += *fansPage;
}

//This methos show all friends and fans pages
void Facebook::showAll() const
{
	vector<User*>::const_iterator itr = users.begin();
	vector<User*>::const_iterator itrEnd = users.end();

	for (; itr != itrEnd; ++itr)
		(*itr)->show();
}

//This method show all friends of a friens/fans page
void Facebook::showAllFriends(const string& name, int flag) const
{
	User* currUser;

	if (flag == FRIEND)
		currUser = isFriendExist(name);
	else
		currUser = isFansPageExist(name);

	if (currUser != nullptr)
			currUser->showUsers();
	else
		cout << "The user don't exist\n";
	
}

//This method  show the last 10 member statuses
void Facebook::show10Statuses(const string& name) const {

	Friend* currFriend = isFriendExist(name);
	if (currFriend != nullptr)
		currFriend->showLastFriendsStatus();
	else
		cout << "The friend don't exist\n";
}

//This method return the Friend* withe given name
Friend* Facebook::isFriendExist(const string& name) const
{
	vector<User*>::const_iterator itr = users.begin();
	vector<User*>::const_iterator itrEnd = users.end();

	for (;itr!=itrEnd ; ++itr)
	{
		Friend* temp = dynamic_cast<Friend*>(*itr);
		if (temp)
		{
			if (temp->getName() == name)
				return temp;
		}
	}
	return nullptr;
}

//This method return the Fan Page* withe given name
FansPage* Facebook::isFansPageExist(const string& name) const
{
	vector<User*>::const_iterator itr = users.begin();
	vector<User*>::const_iterator itrEnd = users.end();

	for (; itr != itrEnd; ++itr)
	{
		FansPage* temp = dynamic_cast<FansPage*>(*itr);
		if (temp)
		{
			if (temp->getName() == name)
				return temp;
		}
	}
	return nullptr;
}

//This method add new user to the array users
void Facebook::addToUsers(User* newUser)
{
	int logSize = users.size(), phySize = users.capacity();

	if (logSize == 0)
		users.reserve(2);
	
	else if(logSize==phySize)
		users.reserve(2*phySize);
	
	users.push_back(newUser);
}