#include "Display.h"
#include "Library.h"
#include <iostream>

using namespace std;

void Display::showMenu() const {
    cout << "\n===== �Ѳ���� =====" << endl;
    cout << "1. �s�W�Ѳ�" << endl;
    cout << "2. ��ܩҦ��Ѳ�" << endl;
    cout << "3. �j�M�Ѳ��]�ҽk�j�M�^" << endl;
    cout << "4. �R���Ѳ�" << endl;
    cout << "5. �ק�Ѳ�" << endl;
    cout << "6. �Ѳ��ƶq�έp" << endl;
    cout << "7. �Ѳ��Ƨǡ]�Ʀr�^" << endl;
    cout << "8. �Ѳ��Ƨǡ]����^" << endl;
    cout << "0. ���}�t��" << endl;
    cout << "�п�J�A����ܡG";
}

void Display::promptForBookDetails(string& title, string& author, string& year, string& category) const {
    cout << "�п�J�Ѳ��G";
    getline(cin, title);
    cout << "�п�J����G";
    getline(cin, author);
    cout << "�п�J�R�J�ɶ��G";
    getline(cin, year);
    cout << "�п�J�����G";
    getline(cin, category);
}

void Display::run(Library& library) const {
    int choice = -1;
    while (choice != 0) {
        showMenu();
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1: {
            string title, author, year, category;
            promptForBookDetails(title, author, year, category);
            library.addBook(Book(title, author, year, category));
            cout << "�Ѳ��w�s�W�C" << endl;
            break;
        }
        case 2:
            library.showAllBooks();
            break;
        case 3: {
            string query;
            cout << "�п�J�n�j�M���Ѳ�������r�G";
            getline(cin, query);
            auto results = library.searchBooks(query);
            if (results.empty()) {
                cout << "�䤣������Ѳ��C" << endl;
            }
            else {
                cout << "��� " << results.size() << " �������Ѳ��G" << endl;
                for (const auto& b : results) {
                    b.display();
                }
            }
            break;
        }
        case 4: {
            string title;
            cout << "�п�J�n�R�����Ѳ��G";
            getline(cin, title);
            library.removeBook(title);
            break;
        }
        case 5: {
            string title, newTitle, newAuthor, newYear, newCategory;
            cout << "�п�J�n�ק諸�Ѳ��G";
            getline(cin, title);
            cout << "�п�J�s�Ѳ��G";
            getline(cin, newTitle);
            cout << "�п�J�s����G";
            getline(cin, newAuthor);
            cout << "�п�J�s�ɶ��G";
            getline(cin, newYear);
            cout << "�п�J�s�����G";
            getline(cin, newCategory);
            library.editBook(title, newTitle, newAuthor, newYear, newCategory);
            break;
        }
        case 6:
            cout << "�Ѳ��w�ثe�@�� " << library.getBookCount() << " ���Ѳ��C" << endl;
            break;
        case 7:
            library.sortBooksByTitle();
            break;
        case 8:
            library.sortBooksByAuthor();
            break;
        case 0:
            cout << "�t�ΧY�N�h�X�A�P�¨ϥΡI" << endl;
            break;
        default:
            cout << "�L�Ī���ܡA�Э��s��J�C" << endl;
            break;
        }
    }
}