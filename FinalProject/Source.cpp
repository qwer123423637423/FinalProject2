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
void User::Info() const
{
	cout << "Ваш ник " << UserName << endl;
	cout << "Ваш пароль " << UserPassword << endl;
}

User::~User()
{
}

//показать входящие сообщения
void User::ShowMesages()
{
	string line;

	ifstream in("mesages.txt");
	if (in.is_open()) 
	{
		while (getline(in, line)) 
		{
			int counter = 0;
			if (line.find("To " + UserName) != string::npos)
			{
				counter += 1;
				int size_of_text =  line.length() - line.find("*");
				cout << (line.substr(line.find("*") + 1, size_of_text)) << endl;
			}
			if (counter == 0) 
			{
				cout << "Входящих сообщений не обнаруженно" << endl;
			}
		}
	}
	in.close();
}
//отправить сообщение
void User::SendMesage(string name, string text) 
{
	ofstream out;
	out.open("mesages.txt", ios::app);
	if (out.is_open()) 
	{
		out << "To " + name + " " + "*" + text + " " + "From " + UserName;
	}
	out.close();
}
// посмотреть сообщение главного чата
void User::SeeGeneral() 
{
	string line;
	ifstream in("general_chat.txt");
	if (in.is_open()) 
	{
		while (getline(in, line)) 
		{
			cout << line << endl;
			printf("\n");
		}
	}
	in.close();
}
//отправить сообщение в главный чат
void User::SendGeneral(string text) 
{
	ofstream out;
	out.open("general_chat.txt", ios::app);
	if (out.is_open()) 
	{
		out << UserName + " " + "Пишет: " + text << endl;
	}
	out.close();
}
