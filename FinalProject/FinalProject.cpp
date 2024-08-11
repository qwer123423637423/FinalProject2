#include <iostream>
#include "Header.h"

int main()
{
    setlocale(LC_ALL, "");
    string username;
    string userpassword;
    while (true) {

        cout << "Введите логин(Без пробелов)" << endl;
        cin >> username;
        cout << endl;
        cout << "Введите пароль(Без Пробелов)" << endl;
        cin >> userpassword;
        cout << endl;

        User user(username, userpassword);
        while (true) {
            printf("Выберите действие с аккаунтом");

            printf("\n");

            cout << "1. Изменить логин" << endl;
            cout << "2. Изменить пароль" << endl;
            cout << "3. Написать сообщение" << endl;
            cout << "4. Информация об аккаунте" << endl;
            cout << "5. Выйти из аккаунта" << endl;

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
            if (answer == 2)
            {
                cout << "Введите пароль" << endl;
                cin >> userpassword;
                cout << endl;
                user.ChangePassword(userpassword);
            }
            if (answer == 3) 
            {
                cout << "Функция в разработке" << endl;
            }
            if (answer == 4)
            {
                user.Info();
                printf("\n");
            }
            if (answer == 5)
            {
                break;
            }
            else 
            {
                cout << "Такого выбора нет" << endl;
                continue;
            }
        }
    }
}
