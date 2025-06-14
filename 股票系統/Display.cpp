#include "Display.h"
#include "Library.h"
#include <iostream>

using namespace std;

void Display::showMenu() const {
    cout << "\n===== 股票選單 =====" << endl;
    cout << "1. 新增股票" << endl;
    cout << "2. 顯示所有股票" << endl;
    cout << "3. 搜尋股票（模糊搜尋）" << endl;
    cout << "4. 刪除股票" << endl;
    cout << "5. 修改股票" << endl;
    cout << "6. 股票數量統計" << endl;
    cout << "7. 股票排序（數字）" << endl;
    cout << "8. 股票排序（價格）" << endl;
    cout << "0. 離開系統" << endl;
    cout << "請輸入你的選擇：";
}

void Display::promptForBookDetails(string& title, string& author, string& year, string& category) const {
    cout << "請輸入股票：";
    getline(cin, title);
    cout << "請輸入價格：";
    getline(cin, author);
    cout << "請輸入買入時間：";
    getline(cin, year);
    cout << "請輸入分類：";
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
            cout << "股票已新增。" << endl;
            break;
        }
        case 2:
            library.showAllBooks();
            break;
        case 3: {
            string query;
            cout << "請輸入要搜尋的股票或關鍵字：";
            getline(cin, query);
            auto results = library.searchBooks(query);
            if (results.empty()) {
                cout << "找不到相關股票。" << endl;
            }
            else {
                cout << "找到 " << results.size() << " 本相關股票：" << endl;
                for (const auto& b : results) {
                    b.display();
                }
            }
            break;
        }
        case 4: {
            string title;
            cout << "請輸入要刪除的股票：";
            getline(cin, title);
            library.removeBook(title);
            break;
        }
        case 5: {
            string title, newTitle, newAuthor, newYear, newCategory;
            cout << "請輸入要修改的股票：";
            getline(cin, title);
            cout << "請輸入新股票：";
            getline(cin, newTitle);
            cout << "請輸入新價格：";
            getline(cin, newAuthor);
            cout << "請輸入新時間：";
            getline(cin, newYear);
            cout << "請輸入新分類：";
            getline(cin, newCategory);
            library.editBook(title, newTitle, newAuthor, newYear, newCategory);
            break;
        }
        case 6:
            cout << "股票庫目前共有 " << library.getBookCount() << " 本股票。" << endl;
            break;
        case 7:
            library.sortBooksByTitle();
            break;
        case 8:
            library.sortBooksByAuthor();
            break;
        case 0:
            cout << "系統即將退出，感謝使用！" << endl;
            break;
        default:
            cout << "無效的選擇，請重新輸入。" << endl;
            break;
        }
    }
}