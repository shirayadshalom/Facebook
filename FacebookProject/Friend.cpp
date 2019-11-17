#include "Friend.h"

//This method show all the friend fans pages
void Friend::showUsers() const
{
	int logSize = users.size();
	vector<User*>::const_iterator itr = users.begin();
	vector<User*>::const_iterator itrEnd = users.end();

	if (logSize == 0)
		cout << "No friends to show\n";
	else
	{
		for (; itr != itrEnd; ++itr)
		{
			Friend* temp = dynamic_cast<Friend*>(*itr);
			if (temp)
				temp->show();
		}
	}
}

//setter
void Friend::setNumOfFriends(int i)
{
	numOfFriends += i;
}

//This method show the 10 updetes statuses
void Friend::showLastFriendsStatus() const
{
	set<Status*, ltStatus> tenStatuses;
	int logSize = users.size(), logStatus;
	vector<User*>::const_iterator itrFriend = users.begin();
	vector<User*>::const_iterator itrEndFriend = users.end();
	vector<Status*>::const_iterator itrStatus, itrEndStatus;
	set<Status*>::iterator itrTen, itrTenEnd;

	if (numOfFriends == 0)
		cout << "No statuses to show\n";
	else
	{
		//get 10 last statuses from each friend
		for (; itrFriend != itrEndFriend; ++itrFriend)
		{
			Friend* temp = dynamic_cast<Friend*>(*itrFriend);
			if (temp)
			{
				logStatus = temp->statuses.size();
				itrStatus = temp->statuses.begin();
				itrEndStatus = temp->statuses.end();
				for (int j = 0; (itrStatus != itrEndStatus && j < 10); j++, ++itrStatus)
					tenStatuses.insert(*itrStatus);
			}
		}

		//show the last 10
		itrTen = tenStatuses.begin();
		itrTenEnd = tenStatuses.end();
		for (int j = 0; (itrTen != itrTenEnd && j < 10); j++, ++itrTen)
			(*itrTen)->showStatus();
	}
}

//operator > - between the number of the users
bool Friend::operator>(const User& other) const
{
	const Friend* temp  = dynamic_cast<const Friend*>(&other);
	if (temp)
		return (numOfFriends > temp->numOfFriends);
	else
		return (numOfFriends > other.getUsers().size());	
}





