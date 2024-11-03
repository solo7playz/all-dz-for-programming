#include "DataBaseRealize.h"

using namespace std;

int main() {
    system("chcp 1251");
    sqlite::database db("users.db");
    AccountManager client(db);
    Games client1(db);
    int choice;
    do {
        cout << "1. Регистрация" << endl;
        cout << "2. Авторизация" << endl;
        cout << "3. Выход" << endl;
        cout << "4. Очистить консоль" << endl;
        cout << "5. Игры" << endl;
        cout << "Выберите действие: ";
        cin >> choice;
        string username, password;
        switch (choice) {
        case 1:
            cout << "Введите имя пользователя: ";
            cin >> username;
            cout << "Введите пароль: ";
            cin >> password;
            client.sign_up_user(db, username, password);
            break;
        case 2:
            cout << "Введите имя пользователя: ";
            cin >> username;
            cout << "Введите пароль: ";
            cin >> password;
            client.log_in_user(db, username, password);
            break;
        case 3:
            system("pause");
            break;
        case 4:
            system("cls");
            break;
        case 5:
            client.show();
            cin >> choice;
            switch (choice) {
            case 1:
                client1.The_gallows();
            case 2:
                system("pause");
            }
        }
    } while (choice != 3);
}