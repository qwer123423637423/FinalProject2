#include "Header.h"
# include <iostream>
using namespace std;


User::User(string name, string password) 
{
	UserName = name;
	UserPassword = password;
}
void User::ChangeName(string name)
{
	UserName = name;
}
void User::ChangePassword(string password)
{
	UserPassword = password;
}
void User::Info()
{
	cout << UserName << endl;
	cout << UserPassword << endl;
}

User::~User()
{
}
