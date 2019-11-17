/*This program provides a social network - Facebook.
the user can add friends, fans pages and stetusess.
*/

#include <iostream>
#include <string.h>
using namespace std;

#include "Facebook.h"
#include "Friend.h"
#include "FansPage.h"
#include "Date.h"
#include "Status.h"
#include "TextImageStatus.h"
#include "TextStatus.h"
#include "TextVideoStatus.h"
#include "VideoStatus.h"
#include "ImageStatus.h"
#include <string>
#include <sstream>
#pragma warning(disable : 4996)

const int CLEAN_BUFF = 1;
const int NOT_CLEAN_BUFF = 0;

//Print the menu
void printMenu()
{
	cout << "-----------------------------\n"
		<< "Please Choose:\n1.Add friend\n2.Add fans page\n3.Add status for a friend or fans page\n"
		<< "4.Show all status\n5.Make friendship\n6.Add new fan\n"
		<< "7.Show all friends and fans pages\n8.Show all friends or fans\n9.Exit\n"
		<< "-----------------------------\n";
}

//Get string from user
void getString(string& str, int flag)
{
	if(flag==CLEAN_BUFF)
		cin.ignore();
	getline(std::cin, str);
}

int main()
{
	Facebook facebook;
	int userChoice, day, month, year, statusType, friendOrFansPage;
	string newName, newStatus, newStatus2, friendA, friendB;
	char ch;
	Status* statusToAdd= nullptr;

	printMenu();

	cin >> userChoice;

	while (userChoice != 9)
	{
		switch (userChoice)
		{
		case 1: {
			//add new friend 
			cout << "Enter a name:\n";
			getString(newName,CLEAN_BUFF);
			cout << "Enter birthday: dd\\mm\\yy \n";
			cin >> day >> ch >> month >> ch >> year;

			Date newDate(day, month, year);
			facebook.addNewFriend(newName, newDate);
			break;
		}
		case 2: {
			//add new fans page
			cout << "Enter a page name:\n";
			getString(newName, CLEAN_BUFF);
			facebook.addNewFansPage(newName);
			break;
		}
		case 3: {
			//add new status
			cout << "Enter 1 for friend, 2 for fans page:\n";
			cin >> friendOrFansPage;
			cout << "Enter name:\n";
			getString(newName, CLEAN_BUFF);
			cout << "Enter status type:\n1. Text 2.Image 3. Video 4.Text and Image 5.Text and Video\n";
			cin >> statusType;
			switch (statusType)
			{
			case 1:cout << "Enter the text\n";
				getString(newStatus,CLEAN_BUFF);
				statusToAdd = new TextStatus(newStatus);
				break;
			case 2: cout << "Enter the image\n";
				getString(newStatus, CLEAN_BUFF);
				statusToAdd = new ImageStatus(newStatus);
				break;
			case 3:  cout << "Enter the video\n";
				getString(newStatus, CLEAN_BUFF);
				  statusToAdd = new VideoStatus(newStatus);
				  break;
			case 4: cout << "Enter the text\n";
				getString(newStatus, CLEAN_BUFF);
				cout << "Enter the image\n";
				getString(newStatus2, NOT_CLEAN_BUFF);
				statusToAdd = new TextImageStatus(TextStatus(newStatus), ImageStatus(newStatus2));
				break;
			case 5:  cout << "Enter the text\n";
				getString(newStatus, CLEAN_BUFF);
				cout << "Enter the video\n";
				getString(newStatus2, NOT_CLEAN_BUFF);
				statusToAdd = new TextVideoStatus(TextStatus(newStatus), VideoStatus(newStatus2));
				break;
			}
			facebook.addNewStatus(newName, friendOrFansPage, statusToAdd);
			break;
		}
		case 4: {
			//show all statuses
			cout << "Enter 1 for friend, 2 for fans page:\n";
			cin >> friendOrFansPage;
			cout << "Enter name:\n";
			getString(newName, CLEAN_BUFF);
			facebook.showAllStatus(newName, friendOrFansPage);
			break;
		}
		case 5: {
			//make friendship
			cout << "Enter first friend's name:\n";
			getString(friendA, CLEAN_BUFF);
			cout << "Enter two friend's name:\n";
			getString(friendB, NOT_CLEAN_BUFF);
			facebook.makeFriendship(friendA, friendB);
			break;
		}
		case 6: {
			//add new fan
			cout << "Enter friend name:\n";
			getString(friendA, CLEAN_BUFF);
			cout << "Enter fans page name:\n";
			getString(newName, NOT_CLEAN_BUFF);
			facebook.addNewFan(friendA, newName);
			break;
		}
		case 7:
		{
			//show all friends and fans pages
			cout << "Showing all friends and all pages listed on Facebook:\n";
			facebook.showAll();
			break;
		}

		case 8: {
			//show all friends
			cout << "Enter 1 for friend, 2 for fans page\n";
			cin >> friendOrFansPage;
			cout << "Enter name:\n";
			getString(newName, CLEAN_BUFF);
			facebook.showAllFriends(newName, friendOrFansPage);
			break;
		}
		
		
		default:
			break;
		}

		printMenu();
		cin >> userChoice;
	}

	cout << "Bye Bye!\n";
}

