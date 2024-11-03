#pragma once
#include <iostream>
#include <string>
#include <sqlite_modern_cpp.h>

using namespace std;

class AccountManager {
    sqlite::database db;
public:
    AccountManager(sqlite::database db) :db(db) {}
    void sign_up_user(sqlite::database& db, const string& username, const string& password) {
        try {
            db << "CREATE TABLE IF NOT EXISTS users (level_in_The_gallows INTEGER, id INTEGER PRIMARY KEY, username TEXT UNIQUE, password TEXT);";
            db << "INSERT INTO users (username, password, level_in_The_gallows) VALUES (?, ?, ?);" << username << password << 1;

            cout << "Регистрация прошла успешно." << endl;
        }
        catch (const sqlite::sqlite_exception& e) {
            cout << "Ошибка регистрации: " << e.what() << endl;
        }
    }
    void sign_up_user(sqlite::database& db) {
        string username, password; cin >> username >> password;
        try {
            db << "CREATE TABLE IF NOT EXISTS users (level_in_The_gallows TEXT, id INTEGER PRIMARY KEY, username TEXT UNIQUE, password TEXT);";
            db << "INSERT INTO users (username, password, level_in_The_gallows) VALUES (?, ?, ?);" << username << password << 1;

            cout << "Регистрация прошла успешно." << endl;
        }
        catch (const sqlite::sqlite_exception& e) {
            cout << "Ошибка регистрации: " << e.what() << endl;
        }
    }

    bool log_in_user(sqlite::database& db, const string& username, const string& password) {
        int count = 0;
        try {
            db << "SELECT COUNT(*) FROM users WHERE username = ? AND password = ?;"
                << username << password >> count;

            if (count > 0) {
                cout << "Авторизация успешна!" << endl;
                return true;
            }
            else {
                cout << "Неверное имя пользователя или пароль." << endl;
                return false;
            }
        }
        catch (const sqlite::sqlite_exception& e) {
            cout << "Ошибка авторизации: " << e.what() << endl;
            return false;
        }
    }
    bool log_in_user(sqlite::database& db) {
        int count = 0;
        string username, password;
        cout << "Введите имя пользователя: ";
        cin >> username;
        cout << "Введите пароль: ";
        cin >> password;
        try {
            db << "SELECT COUNT(*) FROM users WHERE username = ? AND password = ?;"
                << username << password >> count;

            if (count > 0) {
                cout << "Авторизация успешна!" << endl;
                return true;
            }
            else {
                cout << "Неверное имя пользователя или пароль." << endl;
                return false;
            }
        }
        catch (const sqlite::sqlite_exception& e) {
            cout << "Ошибка авторизации: " << e.what() << endl;
            return false;
        }
    }
    void show() {
        cout << "1. Виселица" << endl;
        cout << "2. Выход" << endl;
    }
};
class Games {
    sqlite::database db;
    int level;
public:
    Games(sqlite::database db) :db(db) {}
    void The_gallows() {
        srand(time(0));
        AccountManager cli(db);
        if (cli.log_in_user(db)) {
            int count = 0;
            try {
                level = stoi("SELECT level_in_The_gallows FROM users;");
            }
            catch (exception e) { cout << e.what() << endl; }
            int attempt = 10 - level;
            cout << "Youe level is: " << level << endl;
            string quality;
            vector<string> arr{ "кот", "дом", "мир", "лес", "пол", "зон", "шар", "цвет", "мост", "обед", "вода", "книга", "весы", "рука", "стол", "луг", "помощь", "круг", "бег", "путь" };
            string word = arr[rand() % 20];
            vector<string> pole(word.length());
            for (int i = 0; i < pole.size(); ++i)
                pole[i] = '_';
            print(pole);
            string users_word;
            while (attempt != 0 || exists(pole) != true) {
                cout << endl;
                cin >> users_word;
                for (char item : users_word)
                    for (int i = 0; i < word.length(); ++i)
                        if (item == word[i])
                            pole[i] = word[i];
                print(pole);
                if (users_word.length() != word.length()) {
                    cout << "try again" << endl;
                    print(pole);
                    cin >> users_word;
                    for (char item : users_word)
                        for (int i = 0; i < word.length(); ++i)
                            if (item == word[i])
                                pole[i] = word[i];
                }
                if (exists(pole)) {
                    cout << "You won!" << endl << "Your attempts: " << attempt << endl;
                    level++;
                    try {
                        db << "UPDATE level_in_The_gallows SET"
                            "level_in_The_gallows = ?;"
                            << level;
                    }
                    catch (exception e) { cout << e.what() << endl; } // strange ERROR
                    cout << "Ваш уровень: " << level << endl;
                    return;
                }
                attempt--;
            }
        }
    }
    void print(vector<string> arr) {
        for (string item : arr)
            cout << item << " ";
        cout << endl;
    }
    bool exists(vector<string> arr) {
        int counter = 0;
        for (string item : arr)
            if (item != "_")
                counter++;
            else return false;
        if (counter == arr.size())
            return true;
    }
};