#include "FansPage.h"

//show
void FansPage::show() const {
	cout << "The page name is: ";
	User::show();
}

//operator > - between the number of the users
bool FansPage::operator>(const User& other) const
{
	const Friend* temp = dynamic_cast<const Friend*>(&other);
	if (temp)
		return (users.size() > temp->getNumOfFriends());
	else
		return ((*this) > other);
}