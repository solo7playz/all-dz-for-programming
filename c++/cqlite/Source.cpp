#include "DataBaseRealize.h"

using namespace std;

int main() {
    system("chcp 1251");
    sqlite::database db("users.db");
    AccountManager client(db);
    Games client1(db);
    int choice;
    do {
        cout << "1. �����������" << endl;
        cout << "2. �����������" << endl;
        cout << "3. �����" << endl;
        cout << "4. �������� �������" << endl;
        cout << "5. ����" << endl;
        cout << "�������� ��������: ";
        cin >> choice;
        string username, password;
        switch (choice) {
        case 1:
            cout << "������� ��� ������������: ";
            cin >> username;
            cout << "������� ������: ";
            cin >> password;
            client.sign_up_user(db, username, password);
            break;
        case 2:
            cout << "������� ��� ������������: ";
            cin >> username;
            cout << "������� ������: ";
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