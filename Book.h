//
// Created by Biru Lyu on 3/26/18.
//

#ifndef EE599_LAB8_BOOK_H
#define EE599_LAB8_BOOK_H

#include <string>
#include <fstream>
using namespace std;

class Book {
public:
    Book();
    Book(const string& title, const string& author, const string& ISBN, const string& publisher, unsigned publishedYear);
    void readFrom(istream& in);
    void writeTo(ostream& out) const;
    string getTitle();
    string getAuthor();
    string getISBN();
    string getPublisher();
    unsigned getPublishedYear();
private:
    string title;
    string author;
    string ISBN;
    string publisher;
    unsigned publishedYear;
};

#endif //EE599_LAB8_BOOK_H
