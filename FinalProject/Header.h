#pragma once
# include <iostream>
using namespace std;

class User 
{
public:
	User(string name, string password);
	void ChangeName(string name);
	void ChangePassword(string password);
	void Info();
	~User();

private:
	string UserName;
	string UserPassword;
};