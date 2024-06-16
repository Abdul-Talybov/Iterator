#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Book {
    string title;
    string author;
    int publication_year;

    Book(const string& title, const string& author, int year)
        : title(title), author(author), publication_year(year) {}
};
