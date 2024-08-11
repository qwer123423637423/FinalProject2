#include "Header.h"
# include <iostream>
#include <fstream>
#include <string>
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
void User::Info() const
{
	cout << "Ваш ник" << UserName << endl;
	cout << "Ваш пароль" << UserPassword << endl;
}

User::~User()
{
}

void User::ShowMesages()
{
	string line;

	ifstream in("mesages.txt");
	if (in.is_open()) 
	{
		while (getline(in, line)) 
		{
			if (line.find(UserName) != string::npos)
			{
				int size_of_text =  line.length() - line.find("*");
				cout << (line.substr(line.find("*") + 1, size_of_text)) << endl;
			}
		}
	}
	in.close();
}
void User::SendMesage(string name, string text) 
{
	ofstream out;
	out.open("mesages.txt");
	if (out.is_open()) 
	{
		out << "To " + name + " " + "*" + text + " " + "From " + UserName;
	}
	out.close();
}
