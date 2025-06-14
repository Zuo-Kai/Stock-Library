#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(const string& t, const string& a, const string& y, const string& c)
    : title(t), author(a), year(y), category(c) {
}

string Book::getTitle() const { return title; }
string Book::getAuthor() const { return author; }
string Book::getYear() const { return year; }
string Book::getCategory() const { return category; }

void Book::setTitle(const string& t) { title = t; }
void Book::setAuthor(const string& a) { author = a; }
void Book::setYear(const string& y) { year = y; }
void Book::setCategory(const string& c) { category = c; }

void Book::display() const {
    cout << "�Ѳ��G" << title << "�A���e�G" << author << "�A�ɶ��G" << year << "�A�����G" << category << endl;
}