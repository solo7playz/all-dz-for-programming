#include <iostream>
#include <string>
#include "sqlite_modern_cpp.h"
using namespace sqlite;
using namespace std;

int main() {
    try {
        database db(":memory:");

        db << "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT, password TEXT);";

        string username, password;
        cout << "Введите имя пользователя: ";
        cin >> username;
        cout << "Введите пароль: ";
        cin >> password;

        // Регистрация пользователя
        db << "INSERT INTO users (username, password) VALUES (?, ?);" << username << password;

        // Авторизация пользователя
        string inputUsername, inputPassword;
        cout << "Введите имя пользователя для входа: ";
        cin >> inputUsername;
        cout << "Введите пароль для входа: ";
        cin >> inputPassword;

        row user;
        db << "SELECT * FROM users WHERE username = ? AND password = ?;" << inputUsername << inputPassword >> user;

        if (!user.empty()) {
            cout << "Вы успешно вошли в систему как " << inputUsername << endl;
        }
        else {
            cout << "Ошибка входа: неверное имя пользователя или пароль" << endl;
        }
    }
    catch (exception const& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
