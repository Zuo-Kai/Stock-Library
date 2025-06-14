#include "Library.h"
#include <algorithm>
#include <iostream>

void Library::addBook(const Book& book) { books.push_back(book); }

void Library::showAllBooks() const {
    if (books.empty()) {
        cout << "戈い礚布闽魁" << endl;
        return;
    }
    for (const auto& book : books) {
        book.display();
    }
}

bool Library::hasBook(const string& title) const {
    for (const auto& book : books) {
        if (book.getTitle() == title) {
            return true;
        }
    }
    return false;
}

void Library::removeBook(const string& title) {
    books.erase(remove_if(books.begin(), books.end(), [&](const Book& b) {
        return b.getTitle() == title;
        }), books.end());
    cout << "布" << title << "埃" << endl;
}

int Library::getBookCount() const { return books.size(); }

void Library::editBook(const string& title,
    const string& newTitle,
    const string& newAuthor,
    const string& newYear,
    const string& newCategory) {
    for (auto& book : books) {
        if (book.getTitle() == title) {
            book.setTitle(newTitle);
            book.setAuthor(newAuthor);
            book.setYear(newYear);
            book.setCategory(newCategory);
            cout << "布戈癟穝" << endl;
            return;
        }
    }
    cout << "тぃ璶э布" << endl;
}

void Library::sortBooksByTitle() {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle();
        });
    cout << "布计逼" << endl;
}

void Library::sortBooksByAuthor() {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getAuthor() < b.getAuthor();
        });
    cout << "布基逼" << endl;
}

int Library::levenshteinDistance(const string& s1, const string& s2) const {
    size_t len1 = s1.size(), len2 = s2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
    for (size_t i = 0; i <= len1; ++i) dp[i][0] = i;
    for (size_t j = 0; j <= len2; ++j) dp[0][j] = j;
    for (size_t i = 1; i <= len1; ++i) {
        for (size_t j = 1; j <= len2; ++j) {
            int cost = (tolower(s1[i - 1]) == tolower(s2[j - 1])) ? 0 : 1;
            dp[i][j] = min({ dp[i - 1][j] + 1,
                             dp[i][j - 1] + 1,
                             dp[i - 1][j - 1] + cost });
        }
    }
    return dp[len1][len2];
}

vector<Book> Library::searchBooks(const string& query, int threshold) const {
    vector<Book> results;
    for (const auto& book : books) {
        int dist = levenshteinDistance(book.getTitle(), query);
        if (dist <= threshold) {
            results.push_back(book);
        }
        else {
            string titleLower = book.getTitle();
            string qLower = query;
            transform(titleLower.begin(), titleLower.end(), titleLower.begin(), ::tolower);
            transform(qLower.begin(), qLower.end(), qLower.begin(), ::tolower);
            if (titleLower.find(qLower) != string::npos) {
                results.push_back(book);
            }
        }
    }
    return results;
}