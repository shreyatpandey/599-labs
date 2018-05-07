//
// Created by Biru Lyu on 3/26/18.
//

#include "BookTester.h"
#include "Book.h"
#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

void BookTester::runTests() {

    cout << "Testing class Book..." << endl;
    testConstructors();
    testReadFrom();
    testWriteTo();

    cout << "All tests passed!" << endl;
}

void BookTester::testConstructors() {
    cout << "- constructors... " << flush;
    // default constructor
    Book book;
    assert( book.getTitle() == "" );
    assert( book.getAuthor() == "" );
    assert( book.getISBN() == "" );
    assert( book.getPublisher() == "" );
    assert( book.getPublishedYear() == 0 );
    cout << " 0 " << flush;

    // explicit constructor
    Book book1("Pride and Prejudice", "Jane Austen", "9780141439518", "Penguin Books", 2002);
    assert( book1.getTitle() == "Pride and Prejudice" );
    assert( book1.getAuthor() == "Jane Austen" );
    assert( book1.getISBN() == "9780141439518" );
    assert( book1.getPublisher() == "Penguin Books" );
    assert( book1.getPublishedYear() == 2002 );
    cout << " 1 " << flush;

    cout << " Passed!" << endl;
}

void BookTester::testReadFrom() {
    cout << "- readFrom()... " << flush;
    ifstream fin("input.txt");
    assert( fin.is_open() );
    Book book;

    // read first book in input file
    book.readFrom(fin);
    assert( book.getTitle() == "Pride and Prejudice" );
    assert( book.getAuthor() == "Jane Austen" );
    assert( book.getISBN() == "9780141439518" );
    assert( book.getPublisher() == "Penguin Books" );
    assert( book.getPublishedYear() == 2002 );
    cout << " 0 " << flush;

    // read second book in input file
    string separator;
    getline(fin, separator);
    book.readFrom(fin);
    assert( book.getTitle() == "1984" );
    assert( book.getAuthor() == "George Orwell" );
    assert( book.getISBN() == "9781986508148" );
    assert( book.getPublisher() == "CreateSpace Independent Publishing Platform" );
    assert( book.getPublishedYear() == 2018 );
    cout << " 1 " << flush;

    // read third book in input file
    getline(fin, separator);
    book.readFrom(fin);
    assert( book.getTitle() == "The Great Gatsby" );
    assert( book.getAuthor() == "Francis Scott Fitzgerald" );
    assert( book.getISBN() == "9781985731837" );
    assert( book.getPublisher() == "CreateSpace Independent Publishing Platform" );
    assert( book.getPublishedYear() == 2018 );
    cout << " 2 " << flush;

    fin.close();
    cout << "Passed!" << endl;
}

void BookTester::testWriteTo() {
    cout << "- writeTo()... " << flush;

    // declare three books
    Book book1("Pride and Prejudice", "Jane Austen", "9780141439518", "Penguin Books", 2002);
    Book book2("1984", "George Orwell", "9781986508148", "CreateSpace Independent Publishing Platform", 2018);
    Book book3("The Great Gatsby", "Francis Scott Fitzgerald", "9781985731837", "CreateSpace Independent Publishing Platform", 2018);

    // write the three books to an output file
    ofstream fout("testOutput.txt");
    assert( fout.is_open() );
    book1.writeTo(fout);
    book2.writeTo(fout);
    book3.writeTo(fout);
    fout.close();

    // use readFrom() to see if writeTo() worked
    ifstream fin("testOutput.txt");
    assert( fin.is_open() );
    Book book4, book5, book6;

    // read and check the first book
    book4.readFrom(fin);
    assert( book4.getTitle() == "Pride and Prejudice" );
    assert( book4.getAuthor() == "Jane Austen" );
    assert( book4.getISBN() == "9780141439518" );
    assert( book4.getPublisher() == "Penguin Books" );
    assert( book4.getPublishedYear() == 2002 );
    cout << " 0 " << flush;

    // read and check the second book
    book5.readFrom(fin);
    assert( book5.getTitle() == "1984" );
    assert( book5.getAuthor() == "George Orwell" );
    assert( book5.getISBN() == "9781986508148" );
    assert( book5.getPublisher() == "CreateSpace Independent Publishing Platform" );
    assert( book5.getPublishedYear() == 2018 );
    cout << " 1 " << flush;

    // read and check the third book
    book6.readFrom(fin);
    assert( book6.getTitle() == "The Great Gatsby" );
    assert( book6.getAuthor() == "Francis Scott Fitzgerald" );
    assert( book6.getISBN() == "9781985731837" );
    assert( book6.getPublisher() == "CreateSpace Independent Publishing Platform" );
    assert( book6.getPublishedYear() == 2018 );
    cout << " 2 " << flush;

    fin.close();
    cout << " Passed!" << endl;
}
