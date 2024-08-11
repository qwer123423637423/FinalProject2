#include <iostream>
#include "Header.h"
#include <fstream>
#include <string>

int main()
{
    setlocale(LC_ALL, "");
    string _log;
    string _pas;
    string username;
    string userpassword;
    while (true) {
        int answer = 0;
        cout << "1. Войти" << endl;
        cout << "2. Зарегестрироваться" << endl;
        cin >> answer;
        if (answer == 1)
        {
            while (true) {
                cout << "Введите логин и пароль";
                cin >> username;
                cin >> userpassword;

                string line;
                int flag = 0;
                int counter = 0;
                ifstream in("users.txt");
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        if (line.find(username) != string::npos)
                        {
                            counter += 1;
                            break;
                        }
                    }
                    if (counter > 0)
                    {

                        break;
                    }
                    if (counter == 0)
                    {
                        cout << "Такого пользователя не существует" << endl;
                        continue;
                    }
                }

            }
            
        }
        else if (answer == 2)
        {

            while (true) {
                cout << "Введите логин и пароль" << endl;
                cin >> username;
                cin >> userpassword;
                string line;
                int counter = 0;
                ifstream in("users.txt");
                if (in.is_open())
                {
                    while (getline(in, line))
                    {
                        if (line.find(username) != string::npos)
                        {
                            counter += 1;
                        }
                    }
                    if (counter > 0)
                    {
                        cout << "Придумайте более оригинальный ник" << endl;
                        continue;
                    }
                    else if (counter == 0) 
                    {
                        break;
                    }
                }
            }
            ofstream out;
            out.open("users.txt");
            if (out.is_open()) 
            {
                out << username + " " + userpassword;
            }
            out.close();

        }


        

        User* userr = new User(username, userpassword);
        User& user = *userr;
        while (true) {
            printf("Выберите действие с аккаунтом");

            printf("\n");

            cout << "1. Изменить логин" << endl;
            cout << "2. Изменить пароль" << endl;
            cout << "3. Написать сообщение" << endl;
            cout << "4. Информация об аккаунте" << endl;
            cout << "5. Выйти из аккаунта" << endl;
            cout << "6. Показать входящие сообщения" << endl;

            int answer;

            cin >> answer;
            cout << endl;

            if (answer == 1)
            {
                cout << "Введите имя" << endl;
                cin >> username;
                cout << endl;
                user.ChangeName(username);
            }
            else if (answer == 2)
            {
                cout << "Введите пароль" << endl;
                cin >> userpassword;
                cout << endl;
                user.ChangePassword(userpassword);
            }
            else if (answer == 3) 
            {
                string name, text;
                cout << "Кому отправить?" << endl;
                cin >> name;
                cout << endl;
                cout << "Введите сообщение" << endl;
                cin >> text;
                user.SendMesage(name, text);
            }
            else if (answer == 4)
            {
                user.Info();
                printf("\n");
            }
            else if (answer == 5)
            {   
                delete userr;
                break;
            }
            else if (answer == 6) 
            {
                user.ShowMesages();
            }
            else 
            {
                cout << "Такого выбора нет" << endl;
                continue;
            }
        }
    }
}
